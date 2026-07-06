// Last updated: 06/07/2026, 19:00:18
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int chalk_per_cycle = std::accumulate(chalk.begin(), chalk.end(), static_cast<long long int>(0));

        k = k % chalk_per_cycle;
        int result = 0;
        while (k >= 0){
            if (k < chalk[result]) return result;
            k -= chalk[result];
            result++;
        }
        return -1;
    }
};