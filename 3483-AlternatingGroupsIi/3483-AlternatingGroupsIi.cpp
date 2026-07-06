// Last updated: 06/07/2026, 18:52:41
class Solution {
public:
    int numberOfAlternatingGroups(const vector<int>& colors, const int k) {
        const int n = colors.size();
        int result = 0;
        int left = 0;
        for (int right = 0; right < n + k - 1; ++right){
            if (right > 0 && colors[right % n] == colors[(right - 1) % n]){
                left = right;
            }
            if (right - left + 1 >= k) result++;
        }
        return result;
    }
};