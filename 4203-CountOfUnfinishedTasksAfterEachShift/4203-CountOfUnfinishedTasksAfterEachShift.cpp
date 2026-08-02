// Last updated: 02/08/2026, 14:02:33
class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> prefix(n, 0);
        prefix[0] = tasks[0];
        for (int i = 1; i < n; ++i){
            prefix[i] += prefix[i - 1] + tasks[i];
        }
        int m = shifts.size();
        vector<int> result;
        result.reserve(m);
        long long total = prefix[n - 1];
        long long curr_time = 0;
        for (const int& shift : shifts){
            curr_time += shift;
            if (curr_time >= total){
                result.push_back(0);
                curr_time = 0;
            }
            else {
                auto it = upper_bound(prefix.begin(), prefix.end(), curr_time);
                int completed_task = distance(prefix.begin(), it);
                result.push_back(n - completed_task);
            }
        }
        
        return result;
    }
};