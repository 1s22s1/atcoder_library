#include <vector>
#include <string>

using namespace std;

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
