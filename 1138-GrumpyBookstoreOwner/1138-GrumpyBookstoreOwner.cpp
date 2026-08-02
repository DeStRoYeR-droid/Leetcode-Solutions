// Last updated: 02/08/2026, 14:26:03
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxGain = 0;
        int gain = 0;
        int result = 0;
        for (int i = 0; i < minutes; ++i){
            if (grumpy[i] == 1) gain += customers[i];
            else result += customers[i];
        }
        maxGain = gain;
        for (int i = minutes; i < n; ++i){
            if (grumpy[i - minutes] == 1) gain -= customers[i - minutes];
            if (grumpy[i] == 1) gain += customers[i];
            else result += customers[i];

            maxGain = max(maxGain, gain);
        }

        return result + maxGain;
    }
};