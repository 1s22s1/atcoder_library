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

vector<pair<char, ll>> rle(string s)
{
    vector<pair<char, ll>> vec;

    ll n = s.size();
    ll i = 0;
    while (i < n)
    {
        ll j = i;
        while (j < n && s.at(i) == s.at(j))
        {
            j++;
        }

        vec.emplace_back(s.at(i), j - i);
        i = j;
    }

    return vec;
}
