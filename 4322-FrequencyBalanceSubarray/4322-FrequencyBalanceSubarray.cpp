// Last updated: 06/07/2026, 18:46:52
class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; ++i){
            unordered_map<int, int> mp, mp1;
            for (int j = i; j < n; ++j){
                int val = nums[j];

                if (mp[val]){
                    int freq = mp[val];
                    mp1[freq]--;
                    if (mp1[freq] == 0) mp1.erase(freq);
                }

                mp[val]++;
                mp1[mp[val]]++;

                if (mp.size() == 1 && mp1.size() == 1) result = max(result, j - i + 1);
                else if (mp1.size() == 2){
                    auto it = mp1.begin();
                    int f1 = it->first;
                    ++it;
                    int f2 = it->first;
                    if (f1 == 2 * f2 || f2 == 2 * f1) result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};