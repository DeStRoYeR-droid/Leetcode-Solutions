// Last updated: 06/07/2026, 18:58:12
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> result;
        if (finalSum % 2) return result;

        long long i = 2, cur = 0;

        while (cur + i <= finalSum){
            result.push_back(i);
            cur += i;
            i += 2;
        }

        int size = result.size();
        result[size - 1] += (finalSum - cur);
        return result;
    }
};