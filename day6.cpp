#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

ifstream f("input.in");

vector<string> s;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

bool checked[1001][1001][4];
vector<pair<int,int>>positions;
int ans1,ans2,n,m;

bool isLoop(int pos_i, int pos_j)
{
    int facing = 0, i,j,k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            for(k = 0; k < 4; k++)
                checked[i][j][k] = false;
        }
    }
    checked[pos_i][pos_j][facing] = true;
    while(1)
    {
        int new_i = pos_i + Di[facing];
        int new_j = pos_j + Dj[facing];
        if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m)
            return 0;
        while(s[new_i][new_j] == '#')
        {
          facing++;
          facing %= 4;
          new_i = pos_i + Di[facing];
          new_j = pos_j + Dj[facing];
          if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m)
                return 0;
        }
        if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m)
                return 0;
        if(checked[new_i][new_j][facing] == true)
            return 1;
        else
        {
            checked[new_i][new_j][facing] = true;
            pos_i = new_i;
            pos_j = new_j;
        }
    }
}

int main()
{
    string t;
    int pos_i = 0, pos_j = 0,facing,i,start_i,start_j;
    bool found = false;
    facing = 0;
    while(f>>t)
    {
        s.push_back(t);
        if(t.find('^') < 1e7)
        {
            pos_j = t.find('^');
            found = true;
        }
        else
        {
            if(!found)
                pos_i++;
        }
    }
    n = t.size();
    m = s.size();
    checked[pos_i][pos_j][facing] = true;
    ans1 = 1;
    start_i = pos_i;
    start_j = pos_j;
    while(1)
    {
        int new_i = pos_i + Di[facing];
        int new_j = pos_j + Dj[facing];
        if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m)
            break;
        while(s[new_i][new_j] == '#')
        {
          facing++;
          facing %= 4;
          new_i = pos_i + Di[facing];
          new_j = pos_j + Dj[facing];
          if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m)
                break;
        };
        if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m)
                break;
        if(checked[new_i][new_j][facing] == true)
            break;
        else
        {
            bool isNew = true;
            for(i = 0; i < 4; i++)
            {
                if(checked[new_i][new_j][i] == true)
                    isNew = false;
            }
            checked[new_i][new_j][facing] = true;
            pos_i = new_i;
            pos_j = new_j;
            if(isNew)
            {
                ans1++;
                positions.push_back({new_i, new_j});
            }
        }
    }
    ans2 = 0;
    for(i = 0; i < positions.size(); i++)
    {
        int x = positions[i].first;
        int y = positions[i].second;
        s[x][y] = '#';
        if(isLoop(start_i, start_j))
           ans2++;
        s[x][y] = '.';
    }
    cout<<ans1<<'\n'<<ans2;
    return 0;
}
