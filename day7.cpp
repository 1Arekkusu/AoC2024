#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream f("input.txt");

char line[1001];
long long int v[1001];
int numbers;
long long int ans1, ans2;
bool ok;

long long int convertToNumber(int &pos)
{
    long long int number = 0;
    while(line[pos] >= '0' && line[pos] <= '9')
    {
        number *= 10;
        number += line[pos] - '0';
        pos++;
    }
    return number;
}

long long int concat(long long a, long long b)
{
    long long size_b = 1, c;
    c = b;
    while(c)
    {
        size_b *= 10;
        c /= 10;
    }
    return a * size_b + b;
}

void calcSums(long long int result, int k, long long int sum)
{
    if(ok)
        return;
    if(k == 1)
    {
        calcSums(result, k+1, v[k]);
    }
    else if(k == numbers)
    {
        long long x = concat(sum, v[k]);
        if(sum + v[k] == result || sum * v[k] == result || x == result)
        {
            ok = 1;
            return;
        }
    }
    else
    {
        if(sum + v[k] <= result)
            calcSums(result, k + 1, sum + v[k]);
        if(sum * v[k] <= result)
            calcSums(result, k + 1, sum * v[k]);
        long long x = concat(sum, v[k]);
        if(x <= result)
            calcSums(result, k + 1, x);
    }
}

int main()
{
    int i;
    long long int result;
    while(f.getline(line, 1000))
    {
        numbers = 0;
        i = 0;
        result = convertToNumber(i);
        while(line[i] != '\0')
        {
            while(line[i] < '0' || line[i] >'9')
                i++;
            numbers++;
            v[numbers] = convertToNumber(i);
        }
        ok = 0;
        calcSums(result, 1, 0);
        if(ok)
        {
            ans1 += result;
        }
    }
    cout<<ans1<<" ";
    return 0;
}
