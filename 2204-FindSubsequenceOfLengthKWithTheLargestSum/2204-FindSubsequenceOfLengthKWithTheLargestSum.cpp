// Last updated: 06/07/2026, 18:58:53
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        auto cmp = [&](int a, int b){return nums[a] > nums[b];};
        const int n = nums.size();

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i){
            if (pq.size() < k) pq.push(i);
            else if (nums[pq.top()] < nums[i]){
                pq.pop();
                pq.push(i);
            }
        }

        vector<int> result;
        while (!pq.empty()){
            result.push_back(pq.top()); pq.pop();
        }
        sort(result.begin(), result.end());
        for (int i = 0; i < k; ++i){
            int cur = nums[result[i]];
            result[i] = cur;
        }
        return result;
    }
};