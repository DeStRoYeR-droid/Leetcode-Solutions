// Last updated: 13/07/2026, 22:17:11
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();
        int k = (m + n - 1) / n;
        string A = "";
        for (int i = 0; i < k; i++) A += a;

        function<vector<int>(string&)> z = [&](string &s) {
            int m = s.size();
            vector<int> z(m);
            for (int i = 1, l = 0, r = 0; i < m; i++) {
                if (i <= r) z[i] = min(r - i + 1, z[i - l]);
                while (i + z[i] < m && s[z[i]] == s[i + z[i]]) z[i]++;
                if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
            }
            return z;
        };

        function<bool(string&)> check = [&](string &A) {
            string S = b + "#" + A;
            auto d = z(S);
            for (int x : d) if (x == (int)b.size()) return true;
            return false;
        };

        if (check(A)) return k;
        A += a;
        if (check(A)) return k + 1;
        return -1;
    }
};