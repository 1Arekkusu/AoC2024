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
int ans1,ans2;

int main()
{
    string t;
    int pos_i = 0, pos_j = 0,facing,i;
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
    int n = t.size();
    int m = s.size();
    checked[pos_i][pos_j][facing] = true;
    ans1 = 1;
    while(1)
    {
        int new_i = pos_i + Di[facing];
        int new_j = pos_j + Dj[facing];
        if(new_i < 0 || new_i >= n || new_i < 0 || new_j >= m)
            break;
        while(s[new_i][new_j] == '#')
        {
          facing++;
          facing %= 4;
          new_i = pos_i + Di[facing];
          new_j = pos_j + Dj[facing];
          if(new_i < 0 || new_i >= n || new_i < 0 || new_j >= m)
                break;
        };
        if(new_i < 0 || new_i >= n || new_i < 0 || new_j >= m)
                break;
        if(checked[new_i][new_j][facing] == true)
            break;
        else
        {
            bool isNew = true;
            for(i = 0; i < 4; i++)
            {
                if(checked[new_i][new_j][i] == true)
                {
                    isNew = false;
                    if(i == (facing+1)%4)
                        ans2++;
                }
            }
            checked[new_i][new_j][facing] = true;
            pos_i = new_i;
            pos_j = new_j;
            if(isNew)
                ans1++;
        }
    }
    cout<<ans1<<'\n'<<ans2;
    return 0;
}
