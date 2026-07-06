// Last updated: 06/07/2026, 18:54:10
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int side = min(longestConsecutive(hBars), longestConsecutive(vBars)) + 1;
        return side * side;
    }

    int longestConsecutive(const vector<int>& arr){
        int longest = 1, curr = 1;

        for (int i = 1; i < arr.size(); ++i){
            curr = (arr[i] == arr[i - 1] + 1) ? curr + 1 : 1;
            longest = max(longest, curr);
        }

        return longest;
    }
};