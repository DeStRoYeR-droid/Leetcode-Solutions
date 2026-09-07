// Last updated: 07/09/2026, 22:50:00
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 0;
        long long interval = 1;
        for(int i=0;i<prices.size();i++)
        {
            if(i+1<prices.size() && prices[i] == prices[i+1]+1)
                interval++;
            else{
                res += (interval * (interval + 1)) / 2;
                interval = 1;
            }
        }

        return res;
    }
};