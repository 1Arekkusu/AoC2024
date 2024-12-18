#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

ifstream f("input.txt");

struct patrat{
    int a,p;
};

char s[201][201];
bool visited[201][201];
bool side[201][201][4];
int n,m;
short int Di[4] = {1, -1, 0, 0};
short int Dj[4] = {0, 0, 1, -1};
queue<pair<int,int>> Q;

patrat fil(int x, int y)
{
    int a = 0,p = 0,i,j,k,it;
    visited[x][y] = 1;
    Q.push({x,y});
    while(!Q.empty())
    {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        a += 1;
        for(k = 0; k < 4; k++)
        {
            i = x + Di[k];
            j = y + Dj[k];
            if(i >= 0 && i < n && j >= 0 && j < n)
            {
                if(s[i][j] == s[x][y] && visited[i][j] == 0)
                {
                    visited[i][j] = 1;
                    Q.push({i,j});
                }
                else
                {
                    if(s[i][j] != s[x][y])
                    {
                        side[x][y][k] = 1;
                        bool ok = true;
                        for(it = 0; it < 4; it++)
                        {
                            int new_i = x + Di[it];
                            int new_j = y + Dj[it];
                            if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && s[x][y] == s[new_i][new_j] && side[new_i][new_j][k] == 1)
                                ok = false;
                        }
                        if(ok)p++;
                    }
                }
            }
            else
            {
                side[x][y][k] = 1;
                bool ok = true;
                for(it = 0; it < 4; it++)
                {
                    int new_i = x + Di[it];
                    int new_j = y + Dj[it];
                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && s[x][y] == s[new_i][new_j] && side[new_i][new_j][k] == 1)
                        ok = false;
                }
                if(ok)p++;
            }
        }
    }
    return {a,p};

}

int main()
{
    int ans2 = 0;
    int i,j;
    while(f.getline(s[n], 200))
    {
        n++;
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                patrat x = fil(i,j);
                cout<<x.a<<" "<<x.p<< '\n';
                ans2 += x.a * x.p;
            }
        }
    }
    cout<<ans2;
    return 0;
}
