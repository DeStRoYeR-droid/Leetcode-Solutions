// Last updated: 13/07/2026, 22:17:21
static const double EPS = 1e-6;
class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> values(cards.begin(), cards.end());
        return backtrack(values);
    }

    bool backtrack(const vector<double>& nums){
        if (nums.size() == 1) return fabs(nums[0] - 24.0) < EPS;

        const int n = nums.size();
        // Select nums[i] and nums[j] for operations
        for (int i = 0; i < n - 1; ++i){
            for (int j = i + 1; j < n; ++j){
                vector<double> nextNums;

                // Add the remaining numbers
                for (int k = 0; k < n; ++k){
                    if (k != i && k != j) nextNums.push_back(nums[k]);
                }

                for (double x : combinations(nums[i], nums[j])){
                    nextNums.push_back(x);
                    if (backtrack(nextNums)) return true;
                    nextNums.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> combinations(const double& a, const double& b){
        vector<double> result;
        result.push_back(a + b);
        result.push_back(a - b);
        result.push_back(b - a);
        result.push_back(b * a);

        if (fabs(a) > EPS) result.push_back(b / a);
        if (fabs(b) > EPS) result.push_back(a / b);
        return result;
    }
};