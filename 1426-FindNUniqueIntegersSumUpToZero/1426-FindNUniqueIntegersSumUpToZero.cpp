// Last updated: 06/07/2026, 19:04:23
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for (int i = -n / 2; i <= n / 2; i += 1){
            if (i == 0 && n % 2 == 0) continue;
            result.push_back(i);
        }
        return result;
    }
};