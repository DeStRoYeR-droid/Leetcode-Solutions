// Last updated: 06/07/2026, 18:55:48
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        const int n = nums.size();
        unordered_map<int, int> freq;
        for (const auto& val : nums) freq[val]++;

        vector<bool> possible(n + 1, false);
        for (auto [val, f] : freq){
            int index;
            if (val > 0) index = val % value;
            else {
                int k = ceil((abs(val) + value - 1) / value);
                index = (val + k * value) % value;
            }

            for (int i = 0; index + i <= n; i += value){
                if (possible[index + i]) continue;
                else {
                    f--;
                    possible[index + i] = true;
                }

                if (f == 0) break;
            }
        }

        int result = n + 1;
        for (int i = 0; i < possible.size(); ++i){
            if (!possible[i]){
                result = i;
                break;
            }
        }
        return result;
    }
};