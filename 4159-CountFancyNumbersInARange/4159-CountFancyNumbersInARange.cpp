// Last updated: 06/07/2026, 18:47:41
long long memo[20][200][11][2][2][2];

class Solution {
public:
    long long countFancy(long long l, long long r) {
        return countUpto(r) - countUpto(l - 1);
    }

    bool isGood(int n){
        string s = to_string(n);
        if (s.size() <= 1) return true;

        bool inc = true, dec = true;
        for (int i = 1; i < s.size(); ++i){
            if (s[i] <= s[i - 1]) inc = false;
            if (s[i] >= s[i - 1]) dec = false;
        }
        return inc || dec;
    }

    long long countUpto(long long n){
        string s = to_string(n);
        memset(memo, -1, sizeof(memo));
        return dp(s, 0, 0, 10, true, true, true, false);
    }


    long long dp(const string& s, int idx, int total, int last, bool inc, bool dec, bool tight, bool started){
        if (idx == s.size()){
            return (started && (inc || dec || isGood(total))) ? 1 : 0;
        }

        if (!tight && started && memo[idx][total][last][inc][dec][started] != -1){
            return memo[idx][total][last][inc][dec][started];
        }

        long long count = 0;
        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; ++d){
            bool nextTight = tight && (d == limit);

            if (!started && d == 0){
                count += dp(s, idx + 1, 0, 10, true, true, nextTight, false);
            }
            else if (!started && d > 0){
                count += dp(s, idx + 1, d, d, true, true, nextTight, true);
            }
            else {
                bool nextInc = inc && (d > last);
                bool nextDec = dec && (d < last);

                count += dp(s, idx + 1, total + d, d, nextInc, nextDec, nextTight, true);
            }
        }

        if (!tight && started){
            memo[idx][total][last][inc][dec][started] = count;
        }
        return count;
    }
    
};