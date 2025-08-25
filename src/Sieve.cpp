#include <vector>

using namespace std;

class Sieve
{
public:
    vector<bool> prime_vector;

    Sieve(long long n)
    {
        prime_vector.assign(n + 1, true);

        prime_vector.at(0) = false;
        prime_vector.at(1) = false;

        for (long long p = 2; p <= n; p++)
        {
            if (!prime_vector.at(p))
            {
                continue;
            }

            for (long long q = p * 2; q <= n; q += p)
            {
                prime_vector.at(q) = false;
            }
        }
    }

    bool is_prime(long long n)
    {
        return prime_vector.at(n);
    }
};
