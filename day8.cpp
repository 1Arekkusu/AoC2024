#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream f("input.txt");

int ans1,ans2;
vector<pair<int,int>> v[200];
bool antinodes[1001][1001];
char s[300];

pair<int,int> calcAntinode(int x1, int y1, int x2, int y2)
{
    int distX,distY;
    if(x1 < x2)
        distX = x1 - (x2-x1);
    else
        distX = x1 + (x1-x2);
    if(y1 < y2)
        distY = y1 - (y2-y1);
    else
        distY = y1 + (y1-y2);
    return {distX, distY};
}

int main()
{
    int lines = 0,columns = 0, i, j,k;
    while(f.getline(s, 1000))
    {
        columns = strlen(s);
        for(i = 0; i < strlen(s); i++)
        {
            if(s[i] != '.')
                v[int(s[i])].push_back({lines, i});
        }
        lines++;
    }
    for(k = 0; k < 200; k++)
    {
        if(v[k].size() > 1)
        {
            for(i = 0; i < v[k].size(); i++)
            {
                for(j = i + 1; j < v[k].size(); j++)
                {
                    pair<int,int> pos;
                    int x1 = v[k][i].first;
                    int y1 = v[k][i].second;
                    int x2 = v[k][j].first;
                    int y2 = v[k][j].second;
                    if(antinodes[x1][y1] == 0)
                    {
                        antinodes[x1][y1] = 1;
                        ans1++;
                    }
                    if(antinodes[x2][y2] == 0)
                    {
                        antinodes[x2][y2] = 1;
                        ans1++;
                    }
                    pos = calcAntinode(x1, y1, x2, y2);
                    while(pos.first >= 0 && pos.first < lines && pos.second >= 0 && pos.second < columns)
                    {
                        if(antinodes[pos.first][pos.second] == 0)
                        {
                            ans1++;
                            antinodes[pos.first][pos.second] = true;
                        }
                        y2 = y1;
                        x2 = x1;
                        x1 = pos.first;
                        y1 = pos.second;
                        pos = calcAntinode(x1, y1, x2, y2);
                    }
                    pos = calcAntinode(x2, y2, x1, y1);
                    while(pos.first >= 0 && pos.first < lines && pos.second >= 0 && pos.second < columns)
                    {
                        if(antinodes[pos.first][pos.second] == 0)
                        {
                            ans1++;
                            antinodes[pos.first][pos.second] = true;
                        }
                        x1 = x2;
                        y1 = y2;
                        x2 = pos.first;
                        y2 = pos.second;
                        pos = calcAntinode(x2, y2, x1, y1);
                    }
                }
            }
        }
    }
    cout<<ans1;
    return 0;
}
