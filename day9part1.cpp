#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("input.txt");

char c;
long long int ans1,ans2;
vector<int> v;

int main()
{
    int i = 0, nr,j;
    while(f>>c)
    {
        nr = c - '0';
        if(i % 2 == 0)
        {
            for(j = 1; j <= nr; j++)
            {
                v.push_back(i/2);
            }
        }
        else
        {
            for(j = 1; j <= nr; j++)
            {
                v.push_back(-1);
            }
        }
        i++;
    }
    i = 0;
    j = v.size()-1;
    while(i < j)
    {
        if(v[i] == -1)
        {
            while(v[j] == -1)
                j--;
            swap(v[i], v[j]);
            j--;
        }
        i++;
    }
    i = 0;
    while(v[i] > -1)
    {
        ans1 += v[i] * i;
        i++;
    }
    cout<<ans1;
    return 0;
}
