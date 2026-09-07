// Last updated: 07/09/2026, 22:45:11
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int result = INT_MAX;
        int time = 0, left = 0;
        for (const vector<int>& log : logs){
            result = (log[1] - left > time) ? 
                                log[0] :
                                (log[1] - left == time) ? 
                                        min(result, log[0]) : 
                                        result;
                                        
            time = max(time, log[1] - left);
            left = log[1];
        }
        return result;
    }
};