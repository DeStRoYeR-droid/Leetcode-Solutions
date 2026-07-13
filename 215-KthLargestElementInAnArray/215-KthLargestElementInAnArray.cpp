// Last updated: 13/07/2026, 22:23:20
class Solution {
public:
    int findKthLargest(const vector<int>& nums, const int& k) {
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (const int& num : nums){
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};