// Last updated: 06/07/2026, 19:06:00
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        pq.push(0);

        while (pq.size() > 2){
            int l1 = pq.top(); pq.pop();
            int l2 = pq.top(); pq.pop();

            if (l1 == l2) continue;
            else pq.push(l1 - l2);
        }

        return pq.top();
    }
};