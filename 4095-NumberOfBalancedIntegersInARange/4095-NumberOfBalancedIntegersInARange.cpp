// Last updated: 06/07/2026, 18:48:11
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

// For those spying my code, initialising dp inside class is giving me segmentation fault
long long dp[20][200][200][2][2];

class Solution {
private:
    string s;
    int n;
    
    long long dfs(int pos, int even_sum, int odd_sum, int tight, int started) {
        if (pos == n) {
            return (started && even_sum == odd_sum) ? 1 : 0;
        }
        
        if (dp[pos][even_sum][odd_sum][tight][started] != -1) {
            return dp[pos][even_sum][odd_sum][tight][started];
        }
        
        long long &ans = dp[pos][even_sum][odd_sum][tight][started] = 0;
        int limit = tight ? s[pos] - '0' : 9;
        
        for (int d = 0; d <= limit; d++) {
            int new_even = even_sum;
            int new_odd = odd_sum;
            int new_started = started || (d > 0);
            
            if (new_started) {
                if (pos % 2 == 0) new_even += d;
                else new_odd += d;
            }
            
            int new_tight = tight && (d == limit);
            ans += dfs(pos + 1, new_even, new_odd, new_tight, new_started);
        }
        return ans;
    }
    
public:
    long long count(string num) {
        s = num;
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 0, 1, 0);
    }
    
    long long countBalanced(long long low, long long high) {
        if (low < 10) low = 10;
        string low_minus_one = (low == 10) ? "9" : to_string(low - 1);
        return count(to_string(high)) - count(low_minus_one);
    }
};
