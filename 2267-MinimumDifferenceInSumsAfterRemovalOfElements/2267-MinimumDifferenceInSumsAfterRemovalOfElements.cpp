// Last updated: 06/07/2026, 18:58:18
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        const int n = nums.size();
        int k = n / 3;

        vector<long long> leftMin(n), rightMax(n);
        priority_queue<int> maxLeft;
        priority_queue<int, vector<int>, greater<int>> minRight;

        long long leftSum = 0, rightSum = 0, minDiff = LLONG_MAX;

        for (int i = 0; i < k; ++i){
            maxLeft.push(nums[i]);
            leftSum += nums[i];
        }
        leftMin[k - 1] = leftSum;

        for (int i = k; i < n - k; ++i){
            if (!maxLeft.empty() && nums[i] < maxLeft.top()){
                leftSum += nums[i] - maxLeft.top();
                maxLeft.pop();
                maxLeft.push(nums[i]);
            }
            leftMin[i] = leftSum;
        }

        for (int i = n - 1; i >= n - k; --i){
            minRight.push(nums[i]);
            rightSum += nums[i];
        }
        rightMax[n - k] = rightSum;

        for (int i = n - k - 1; i >= k; --i){
            if (!minRight.empty() && nums[i] > minRight.top()){
                rightSum += nums[i] - minRight.top();
                minRight.pop();
                minRight.push(nums[i]);
            }
            rightMax[i] = rightSum;
        }

        for (int i = k - 1; i < n - k; ++i){
            minDiff = min(minDiff, leftMin[i] - rightMax[i+1]);
        }
        return minDiff;
    }
};