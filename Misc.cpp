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
