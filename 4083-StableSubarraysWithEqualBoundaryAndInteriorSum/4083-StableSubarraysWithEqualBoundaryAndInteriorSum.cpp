// Last updated: 06/07/2026, 18:48:17
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        const int n = capacity.size();
        if (n < 3) return 0;
        vector<long long> prefix(n);
        prefix[0] = capacity[0];
        for (int i = 1; i < n; ++i){
            prefix[i] += prefix[i - 1] + capacity[i];
        }


        long long result = 0;
        unordered_map<int, unordered_map<long long, int>> prefixCount;
        prefixCount[capacity[0]][prefix[0]]++;

        for (int r = 2; r < n; ++r){
            long long target = prefix[r - 1] - capacity[r];
            int val = capacity[r];

            if (prefixCount.count(val) && prefixCount[val].count(target)){
                result += prefixCount[val][target];
            }

            prefixCount[capacity[r - 1]][prefix[r-  1]]++;
        }
        return result;
    }
};