// Last updated: 06/07/2026, 18:53:57
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[100] = {0};
        int result = 0, maxFreq = 0;
        for (const auto& num : nums){
            freq[num - 1]++;
            if (freq[num - 1] > maxFreq){
                result = freq[num - 1];
                maxFreq = freq[num - 1];
            }
            else if (freq[num - 1] == maxFreq) result += freq[num - 1];
        }
        return result;
    }
};