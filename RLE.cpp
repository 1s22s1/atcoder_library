#include <vector>
#include <string>

using namespace std;

vector<pair<char, int>> rle(string s)
{
    vector<pair<char, int>> vec;

    int i = 0;
    while (i < s.size())
    {
        int j = i;
        while (j < s.size() && s.at(i) == s.at(j))
        {
            j++;
        }

        vec.push_back({s.at(i), j - i});
        i = j;
    }

    return vec;
}
