// Last updated: 06/07/2026, 19:06:28
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> counting(n + 1, 0);
        for (const auto& val : trust){
            counting[val[1]]++;
            counting[val[0]]--;
        }

        for (int i = 1; i <= n; ++i){
            if (counting[i] == n - 1) return i;
        }
        return -1;
    }
};