// Last updated: 06/07/2026, 18:58:49
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> mp(10, 0);
        for (const auto& val : digits) mp[val]++;

        vector<int> result;
        for (int i = 1; i <= 9; ++i){
            if (mp[i] == 0) continue;
            --mp[i];
            for (int j = 0; j <= 9; ++j){
                if (mp[j] == 0) continue;
                --mp[j];
                for (int k = 0; k <= 8; k += 2){
                    if (mp[k] == 0) continue;
                    --mp[k];
                    result.push_back(100 * i + 10 * j + k);
                    ++mp[k];
                }
                ++mp[j];
            }
            ++mp[i];

        }
        return result;
    }
};