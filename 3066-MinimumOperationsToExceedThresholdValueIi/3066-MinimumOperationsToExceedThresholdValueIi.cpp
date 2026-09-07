// Last updated: 07/09/2026, 22:38:07
namespace {
    const int _ = []{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
}
class Solution {
public:
    int minOperations(const vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int result = 0;
        while (pq.top() < k){
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();

            pq.push(2*x + y);
            result++;
        }
        return result;
    }
};