// Last updated: 06/07/2026, 18:54:52
class Solution {
public:
    int minimumIndex(const vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> freq;
        int dom = 0, count = 0;

        for (const int& num : nums) freq[num]++;
        for (auto& [num, c] : freq){
            if (c > n / 2){
                dom = num;
                count = c;
                break;
            }
        }

        int leftCount = 0;
        for (int i = 0; i < n - 1; ++i){
            if (nums[i] == dom) leftCount++;
            int leftSize = i + 1;
            int rightSize = n - leftSize;
            int rightCount = count - leftCount;

            if (leftCount > leftSize / 2 && rightCount > rightSize / 2) return i;
        }

        return -1;
    }
};