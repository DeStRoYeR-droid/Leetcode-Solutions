// Last updated: 14/09/2026, 09:34:35
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int result = 0;
        for (int& work : worker){
            int allocated_profit = 0;
            for (int i = 0; i < difficulty.size(); i++)
                if (difficulty[i] <= work) 
                    allocated_profit = max(allocated_profit, profit[i]);
            result += allocated_profit;   
        }
        return result;
    }
};