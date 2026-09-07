// Last updated: 07/09/2026, 22:25:25
class Solution {
public:
    string lexSmallest(string s) {
        const int n = s.size();
        string result = s;

        string temp = s;
        for (int k = 1; k <= n; ++k){
            temp = s;
            reverse(temp.begin(), temp.begin() + k);
            result = min(result, temp);

            temp = s;
            reverse(temp.end() - k, temp.end());
            result = min(result, temp);
        }
        return result;
    }
};