// Last updated: 07/09/2026, 22:31:13
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> mp(10, 0);
        for (const auto& val : digits) mp[val]++;

        set<int> result;
        for (int i = 1; i <= 9; ++i){
            if (mp[i] == 0) continue;
            --mp[i];
            for (int j = 0; j <= 9; ++j){
                if (mp[j] == 0) continue;
                --mp[j];
                for (int k = 0; k <= 8; k += 2){
                    if (mp[k] == 0) continue;
                    --mp[k];
                    result.insert(100 * i + 10 * j + k);
                    ++mp[k];
                }
                ++mp[j];
            }
            ++mp[i];

        }
        return result.size();
    }
};