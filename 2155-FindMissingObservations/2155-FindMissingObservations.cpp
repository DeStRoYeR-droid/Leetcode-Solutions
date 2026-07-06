// Last updated: 06/07/2026, 18:59:16
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int cur_sum = accumulate(rolls.begin(), rolls.end(), 0);
        int actual_sum = mean * (rolls.size() + n);

        int missing = actual_sum - cur_sum;
        if (missing < n) return vector<int>(); 
        if (missing > n * 6) return vector<int>();
        vector<int> result;

        while (n > 0){
            result.push_back(missing / n);
            missing = missing - missing / n;
            n--;
        }
        return result;
    }
};