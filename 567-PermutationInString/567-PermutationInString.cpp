// Last updated: 13/07/2026, 22:18:23
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n = s1.size(), m = s2.size();

        if (n > m) return false;

        vector<int> arrS1(26, 0), arrS2(26, 0);
        for (const char& ch : s1) arrS1[ch - 'a']++;
        for (int i = 0; i < n; ++i) arrS2[s2[i] - 'a']++;

        // printVector(arrS1);
        // printVector(arrS2);

        int left = 0;
        for (int i = n; i < m; ++i, ++left){
            // printVector(arrS1);
            // printVector(arrS2);
            if (equateEncoding(arrS1, arrS2)) return true;
            arrS2[s2[left] - 'a']--;
            arrS2[s2[i] - 'a']++;
        }
        if (equateEncoding(arrS1, arrS2)) return true;
        return false;
    }

    bool equateEncoding(const vector<int>& a, const vector<int>& b){
        for (int i = 0; i < 26; ++i){
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    void printVector(const vector<int>& vec){
        for (const auto& val : vec) cout << val << " ";
        cout << endl;
    }
};