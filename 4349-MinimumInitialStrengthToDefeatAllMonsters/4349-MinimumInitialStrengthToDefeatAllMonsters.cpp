// Last updated: 02/08/2026, 14:01:35
class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        vector<long long> power(n + 1, 0);
        for (int i = 0; i < boosts.size(); ++i){
            int l = boosts[i][0];
            int r = boosts[i][1];
            int v = boosts[i][2];

            power[l] += v;
            if (r + 1 < n) power[r + 1] -= v;
        }

        vector<long long> bonus(n);
        long long curr = 0;
        long long hi = 0;
            
        for (int i = 0; i < n; ++i){
            hi += monsters[i];

            curr += power[i];
            bonus[i] = curr;
        }
        long long lo = 0;
        long long result = 0;
            
        while (lo <= hi){
            long long mid = lo + (hi - lo) / 2;

            if (check(bonus, monsters, mid)){
                result = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        

        return result;
    }

    bool check(vector<long long>& cur, vector<int>& monsters, long long start){
        for (int i = 0; i < monsters.size(); ++i){
            if (start + cur[i] < monsters[i]){
                return false;
            }

            start -= monsters[i];
            if (start < 0) start = 0;
        }
        return true;
    }
};