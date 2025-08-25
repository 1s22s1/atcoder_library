#include <vector>
#include <string>

using namespace std;

#define ll long long

ll mod(ll a, ll n, ll p)
{
    if (n == 1)
    {
        return a % p;
    }

    if (n % 2 == 1)
    {
        return (a * mod(a, n - 1, p)) % p;
    }

    ll tmp = mod(a, n / 2, p);
    return (tmp * tmp) % p;
}

vector<pair<char, long long>> rle(string s)
{
    vector<pair<char, long long>> vec;

    long long i = 0;
    while (i < s.size())
    {
        long long j = i;
        while (j < s.size() && s.at(i) == s.at(j))
        {
            j++;
        }

        vec.push_back({s.at(i), j - i});
        i = j;
    }

    return vec;
}
