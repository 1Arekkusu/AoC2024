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
int n,m;
short int Di[4] = {1, -1, 0, 0};
short int Dj[4] = {0, 0, 1, -1};
queue<pair<int,int>> Q;

patrat fil(int x, int y)
{
    int a = 0,p = 0,i,j,k;
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
                        p++;
                }
            }
            else
            {
                p++;
            }
        }
    }
    return {a,p};

}

int main()
{
    int ans1 = 0;
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
                cout<<x.a<<" "<<x.p<<'\n';
                ans1 += x.a * x.p;
            }
        }
    }
    cout<<ans1;
    return 0;
}
