#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

ifstream f("input.txt");

short int a[101][101];
int n,m;
bool visited[101][101];
char s[101];
queue<pair<int,int>> Q;
short int Di[4] = {1, -1, 0, 0};
short int Dj[4] = {0, 0, 1, -1};

int lee(int x, int y)
{
    int i,j, nr = 0;
    Q.push({x, y});
    while(!Q.empty())
    {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for(i = 0; i < 4; i++)
        {
            int new_x = x + Di[i];
            int new_y = y + Dj[i];
            if(a[new_x][new_y] == a[x][y] + 1)
            {
                if(a[new_x][new_y] == 9)
                    nr++;
                else
                    Q.push({new_x, new_y});
            }
        }
    }
    return nr;
}

int main()
{
    int ans1 = 0;
    int i,j;
    n = 0;
    while(f.getline(s,100))
    {
        n++;
        m = strlen(s);
        for(j = 1; j <= m; j++)
        {
            a[n][j] = s[j-1] - '0';
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i][j] == 0)
            {
                ans1 += lee(i, j);
            }
        }
    }
    cout<<ans1;
    return 0;
}
