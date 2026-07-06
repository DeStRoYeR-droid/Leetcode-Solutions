// Last updated: 06/07/2026, 18:48:39
// g++ -std=c++17 test.cpp -o test.out && ./test.out
#include <vector>
#include<iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> digits;
    long long memo[20][2][2];

    long long dfs(int pos, bool bounded, bool started) {
        if (pos == (int)digits.size()) {
            return started ? 1 : 0;
        }
        if (memo[pos][bounded][started] != -1)
            return memo[pos][bounded][started];

        int limit = bounded ? digits[pos] : 9;
        long long res = 0;

        for (int dig = 0; dig <= limit; dig++) {
            if (dig == 0 && !started) {
                res += dfs(pos + 1, bounded && (dig == limit), false);
            }
            else if (dig != 0) {
                res += dfs(pos + 1, bounded && (dig == limit), true);
            }
        }
        return memo[pos][bounded][started] = res;
    }

    long long countDistinct(long long n) {
        digits.clear();
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());

        memset(memo, -1, sizeof(memo));
        return dfs(0, true, false);
    }
};

