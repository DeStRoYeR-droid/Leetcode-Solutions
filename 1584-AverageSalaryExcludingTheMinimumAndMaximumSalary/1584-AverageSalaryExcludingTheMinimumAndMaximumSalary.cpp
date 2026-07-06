// Last updated: 06/07/2026, 19:02:50
class Solution {
public:
    double average(vector<int>& salary) {
        double result = 0;
        const int n = salary.size();
        sort(salary.begin(), salary.end());
        result = accumulate(salary.begin() + 1, salary.end() - 1, 0);
        return result / (n - 2);
    }
};