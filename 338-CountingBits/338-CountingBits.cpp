// Last updated: 13/07/2026, 22:20:58
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int cur;
        for (int j = 0; j <= n; j++){
            cur = 0;
            int i = j;
            while (i > 0){
                cur += i & 1;
                i = i >> 1;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};