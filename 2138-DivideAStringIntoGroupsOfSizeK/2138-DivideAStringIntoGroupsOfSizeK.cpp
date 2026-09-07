// Last updated: 07/09/2026, 22:49:26
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        const int n = s.size();

        for (int i = 0; i < n; i += k){
            if (i + k < n) result.push_back(s.substr(i, k));
            else {
                string cur = s.substr(i, k);
                while (cur.size() < k) cur += fill;
                result.push_back(cur);
            }
        }
        return result;
    }
};