// Last updated: 06/07/2026, 18:55:54
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size();
        vector<pair<int, int>> ess(n);
        for (int i = 0; i < n; ++i) ess[i] = {nums2[i], nums1[i]};

        sort(rbegin(ess), rend(ess));

        long long sumS = 0, result = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto& [e, s] : ess){
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k){
                sumS -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) result = max(result, sumS * e);
        }
        return result;
    }
};