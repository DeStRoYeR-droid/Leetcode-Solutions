// Last updated: 13/07/2026, 22:26:13
class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if (totalGas < totalCost) return -1;

        int curGas = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); ++i){
            curGas += gas[i] - cost[i];
            if (curGas < 0){
                curGas = 0;
                start = i + 1;
            }
        }

        return start;
    }
};