// Last updated: 06/07/2026, 19:01:19
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        const int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int apples_eaten = 0;
        int day = 0;
    
        while (day < n || !pq.empty()) {
            while (!pq.empty() && pq.top().first <= day) {
                pq.pop();
            }
    
            if (day < n && apples[day] > 0) {
                pq.push({day + days[day], apples[day]});
            }
    
            if (!pq.empty()) {
                auto current = pq.top();
                pq.pop();
                apples_eaten++;
                if (current.second > 1) {
                    pq.push({current.first, current.second - 1});
                }
            }
            day++;
        }
        return apples_eaten;
    }
};