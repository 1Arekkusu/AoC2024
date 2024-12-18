#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

ifstream f("input.txt");

map<long long, long long> m;

int main()
{
    long long ans = 0;
    long long a, blinks,i,j,digits,power;
    blinks = 75;
    while(f>>a)
    {
        if(m.count(a) == 0)
        {
            m[a] = 1;
        }
        else
            m[a]++;
    }
    for(i = 1; i <= blinks; i++)
    {
        vector<pair<long long,long long>> updates;
        for(map<long long, long long>::iterator it = m.begin(); it != m.end(); it++)
        {
            long long val = it->first;
            long long nr = it->second;
            if(val == 0)
            {
                m[val] = 0;
                updates.push_back({1, nr});
            }
            else
            {
                digits = 0;
                power = 1;
                long long c = val;
                while(c > 0)
                {
                    digits++;
                    if(!(digits%2))power *= 10;
                    c /= 10;
                }
                if(digits % 2 == 0)
                {
                    updates.push_back({val%power, nr});
                    updates.push_back({val/power, nr});
                }
                else
                {
                    updates.push_back({val*2024, nr});
                }
                m[val] = 0;
            }
        }
        for(j = 0; j < updates.size(); j++)
        {
            if(m.count(updates[j].first) == 0)
            {
                m[updates[j].first] = updates[j].second;
            }
            else
                m[updates[j].first] += updates[j].second;
        }
    }
    for(map<long long, long long>::iterator it = m.begin(); it != m.end(); it++)
    {
        ans += it->second;
    }
    cout<<ans;
    return 0;
}
