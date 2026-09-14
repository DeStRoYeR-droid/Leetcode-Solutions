// Last updated: 14/09/2026, 09:25:26
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