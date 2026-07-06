// Last updated: 06/07/2026, 18:59:50
class Solution {
    const static int mod = 1e9 + 7;
    int m, n;
    vector<int> validMasks;
    unordered_map<int, vector<int>> nextMasks;
    unordered_map<long long, int> memo;

    bool isCompatible(int a, int b){
        for (int i = 0; i < m; ++i){
            if ((a % 3) == (b % 3)) return false;
            a /= 3;
            b /= 3;
        }
        return true;
    }

    bool isValid(int mask){
        int prev = -1;
        for (int i = 0; i < m; ++i){
            int cur = mask % 3;
            if (cur == prev) return false;
            prev = cur;
            mask /= 3;
        }
        return true;
    }

    void generateValidMasks(){
        int maxMask = pow(3, m);
        for (int mask = 0; mask < maxMask; ++mask){
            if (isValid(mask)) validMasks.push_back(mask);
        }

        for (int mask : validMasks){
            for (int mask2 : validMasks){
                if (isCompatible(mask, mask2)) nextMasks[mask].push_back(mask2);
            }
        }
    }

    int dfs(int col, int prev){
        if (col == n) return 1;
        long long key = ((long long) col << 10) | prev;
        if (memo.count(key)) return memo[key];

        int result = 0;
        for (int next : nextMasks[prev]) result = (result + dfs(col + 1, next)) % mod;
        return memo[key] = result;
    }

public:
    int colorTheGrid(int m_, int n_) {
        m = m_;
        n = n_;
        generateValidMasks();

        int result = 0;
        for (int mask : validMasks){
            result = (result + dfs(1, mask)) % mod;
        }
        return result;
    }
};