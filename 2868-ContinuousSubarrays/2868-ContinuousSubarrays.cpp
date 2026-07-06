// Last updated: 06/07/2026, 18:54:59
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int left = 0;
        long long result = 0;

        deque<int> minD, maxD;

        for (int right = 0; right < nums.size(); right++){
            while (!minD.empty() && nums[minD.back()] >= nums[right]) minD.pop_back();
            while (!maxD.empty() && nums[maxD.back()] <= nums[right]) maxD.pop_back();

            minD.push_back(right);
            maxD.push_back(right);

            while (nums[maxD.front()] - nums[minD.front()] > 2){
                left++;
                if (minD.front() < left) minD.pop_front();
                if (maxD.front() < left) maxD.pop_front();
            }

            result += right - left + 1;
        }
        return result;
    }
};