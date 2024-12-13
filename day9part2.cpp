#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

ifstream f("input.txt");

struct numere{
    int length,val,start;
}a;

vector<int> v;
vector<numere> numbers;
long long ans2;

int main()
{
    char c;
    int i = 0, j,pos = 0;
    int x;
    while(f>>c)
    {
        a.length = c - '0';
        if(i % 2 == 0)
        {
            for(j = 1; j <= a.length; j++)
            {
                v.push_back(i/2);
            }
            a.val = i/2;
            a.start = pos;
            numbers.push_back(a);
        }
        else
        {
            for(j = 1; j <= a.length; j++)
                v.push_back(-1);
        }
        pos += a.length;
        i++;
    }
    for(i = numbers.size() - 1; i > 0; i--)
    {
        a.length = numbers[i].length;
        a.val = numbers[i].val;
        a.start = numbers[i].start;
        int l = 0;
        int pos = -1;
        for(j = 0; j < a.start; j++)
        {
            if(v[j] == -1)
            {
                if(l == 0)
                {
                    pos = j;
                }
                l++;
            }
            else
            {
                l = 0;
            }
            if(l == a.length)
            {
                break;
            }
        }
        if(l == a.length)
        {
            for(j = pos; j < pos + a.length; j++)
                v[j] = a.val;
            for(j = a.start; j < a.start + a.length; j++)
                v[j] = -1;
        }
    }
    for(i = 0; i < v.size(); i++)
    {
        if(v[i] != -1)
            ans2 += 1LL * v[i] * i;
    }
    cout<<ans2;
    return 0;
}
