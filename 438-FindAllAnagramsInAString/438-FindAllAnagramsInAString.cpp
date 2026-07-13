// Last updated: 13/07/2026, 22:19:42
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n = p.size(), m = s.size();
        vector<int> result;
        if (n > m) return result;

        vector<int> pEncoding(26, 0);
        for (const char& ch : p) pEncoding[ch - 'a']++;

        vector<int> sEncoding(26, 0);
        for (int i = 0; i < n; ++i) sEncoding[s[i] - 'a']++;

        int left = 0;
        for (int right = n; right < m; ++right, ++left){
            if (equateEncoding(pEncoding, sEncoding)) result.push_back(left);
            sEncoding[s[left] - 'a']--;
            sEncoding[s[right] - 'a']++;
        }
        if (equateEncoding(pEncoding, sEncoding)) result.push_back(left);
        return result;
    }

    bool equateEncoding(const vector<int>& a, const vector<int>& b){
        for (int i = 0; i < 26; ++i){
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};