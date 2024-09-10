#include <exercises/hackerrank/warmup/simple_array_sum.hpp>

/**
 * @link Problem definition [[docs/hackerrank/warmup/simple_array_sum.md]]
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


namespace hackerrank::warmup {

    int simpleArraySum(const std::vector<int>& ar) {
        int accum = 0;

        for(const int i : ar)  {
            accum += i;
        }
        return accum;
    }

}
