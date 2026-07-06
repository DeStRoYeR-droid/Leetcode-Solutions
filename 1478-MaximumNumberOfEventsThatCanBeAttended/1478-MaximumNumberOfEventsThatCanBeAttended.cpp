// Last updated: 06/07/2026, 19:03:44
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> heap;

        int day = 0, index = 0, n = events.size(), result = 0;
        while (!heap.empty() || index < n){
            if (heap.empty()){
                day = events[index][0];
            }

            while (index < n && events[index][0] <= day){
                heap.push(events[index][1]);
                ++index;
            }

            heap.pop();
            ++result;
            ++day;

            while (!heap.empty() && heap.top() < day) heap.pop();
        }

        return result;
    }
};