// Last updated: 06/07/2026, 19:04:53
struct Job{
    int start, end, profit;
};
bool compareJobTime(const Job& j1, const Job& j2){return j1.end < j2.end;}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int length = startTime.size();

        int cur = startTime[0] + endTime[0];
        bool isEqtime = true;
        for (int i = 1; i < length; i++)
            if (startTime[i] + endTime[i] != cur) isEqtime = false;

        if (isEqtime)
            return *max_element(profit.begin() , profit.end());
        
        vector<Job> jobs(length);
        for (int i = 0; i < length; i++)
            jobs[i] = {startTime[i] , endTime[i] , profit[i]};
        
        sort(jobs.begin() , jobs.end(), compareJobTime);

        vector<int> dp(length);
        dp[0] = jobs[0].profit;

        for (int i = 1; i < length; i++){
            int profit = jobs[i].profit;
            int lastColl = -1;

            for (int j = i-1; j >= 0; j--){
                if (jobs[j].end <= jobs[i].start){
                    lastColl = j;
                    break;
                }
            }

            profit += (lastColl == -1) ? 0 : dp[lastColl];
            dp[i] = max(dp[i-1] , profit);
        }
        return dp[length - 1];
    }
};


