#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("input.in");

vector<string> s;
string t;

int n,m;
int Di[8] = {0,  0, 1, -1, 1, -1,  1, -1};
int Dj[8] = {1, -1, 0,  0, 1,  1, -1, -1};
char check_list[3] = {'M', 'A', 'S'};

int check_part_one(int i, int j)
{
    int direction,k;
    int ok;
    int nr = 0;
    for(direction = 0; direction < 8; direction++)
    {
        int base_i = i;
        int base_j = j;
        ok = 1;
        for(k = 0; k < 3; k++)
        {
            if(base_i + Di[direction] >= 0 && base_i + Di[direction] < n && base_j + Dj[direction] >= 0 && base_j + Dj[direction] < n)
            {
                base_i += Di[direction];
                base_j += Dj[direction];
                if(s[base_i][base_j] != check_list[k])
                {
                    ok = 0;
                    break;
                }
            }
            else
                ok = 0;
        }
        if(ok)
            nr++;
    }
    return nr;
}

bool check_part_two(int i, int j)
{
    if(i - 1 < 0 || i + 1 >= n || j - 1 < 0 || j + 1 >= n)
        return 0;
    if(s[i+1][j+1] != 'M' && s[i-1][j-1] != 'M')
        return 0;
    if(s[i+1][j+1] != 'S' && s[i-1][j-1] != 'S')
        return 0;
    if(s[i+1][j-1] != 'M' && s[i-1][j+1] != 'M')
        return 0;
    if(s[i+1][j-1] != 'S' && s[i-1][j+1] != 'S')
        return 0;
    return 1;
}

int main()
{
    int ans1 = 0, ans2 = 0;
    int i,j;
    while(f>>t)
        s.push_back(t);

    n = s.size();
    m = s[0].size();
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(s[i][j] == 'X')
            {
                ans1 += check_part_one(i, j);
            }
            if(s[i][j] == 'A')
            {
                ans2 += check_part_two(i, j);
            }
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
