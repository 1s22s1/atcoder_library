#include <vector>

using namespace std;

class Sieve
{
public:
    vector<bool> prime_vector;

    Sieve(int n)
    {
        prime_vector.assign(n + 1, true);

        prime_vector.at(0) = false;
        prime_vector.at(1) = false;

        for (int p = 2; p <= n; p++)
        {
            if (!prime_vector.at(p))
            {
                continue;
            }

            for (int q = p * 2; q <= n; q += p)
            {
                prime_vector.at(q) = false;
            }
        }
    }

    bool is_prime(int n)
    {
        return prime_vector.at(n);
    }
};
