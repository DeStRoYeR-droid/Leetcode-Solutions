// Last updated: 06/07/2026, 18:51:41
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        const int m = queries.size();

        vector<int> workload(n + 1, 0);
        sort(queries.begin(), queries.end());
        priority_queue<int> available;

        int index = 0;

        for (int time = 0; time < n; ++time){
            if (time > 0) workload[time] += workload[time - 1];

            while (index < m && queries[index][0] == time){
                available.push(queries[index][1]);
                ++index;
            }

            while (workload[time] < nums[time]){
                if (available.empty() || available.top() < time) return -1;

                workload[time]++;
                workload[available.top() + 1]--;
                available.pop();
            }
        }
        return available.size();
    }
};