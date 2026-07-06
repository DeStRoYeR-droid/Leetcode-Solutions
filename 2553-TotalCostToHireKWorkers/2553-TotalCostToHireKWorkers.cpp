// Last updated: 06/07/2026, 18:56:21
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost = 0;
        priority_queue<int, vector<int>, greater<>> pq1;
        priority_queue<int, vector<int>, greater<>> pq2;
        int i = 0; 
        int j = costs.size() - 1;
        while (k--){
            while (pq1.size() < candidates && i <= j){
                pq1.push(costs[i++]);
            }
            while (pq2.size() < candidates && i <= j){
                pq2.push(costs[j--]);
            }

            int t1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int t2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (t1 <= t2){
                cost += t1;
                pq1.pop();
            }
            else{
                cost += t2;
                pq2.pop();
            }
        }
        return cost;
    }
};