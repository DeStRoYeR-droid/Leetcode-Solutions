// Last updated: 06/07/2026, 18:48:52
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        int oddCount = 0;
        char oddChar = '\0';
        for (auto& [ch, cnt] : freq) {
            if (cnt % 2 == 1) {
                oddCount++;
                oddChar = ch;
            }
        }
        if (oddCount > 1) return "";

        vector<int> halfCount(26, 0);
        for (auto& [ch, cnt] : freq) {
            halfCount[ch - 'a'] = cnt / 2;
        }

        string result = "";

        function<bool(int, string&, unordered_map<char,int>&, bool)> backtrack =
            [&](int pos, string& curr, unordered_map<char,int>& used, bool tight) -> bool {
                if (pos == n / 2) {
                    string pal = curr;
                    if (oddChar != '\0') pal += oddChar;
                    for (int i = curr.size() - 1; i >= 0; i--) pal += curr[i];

                    if (pal > target) {
                        result = pal;
                        return true;
                    }
                    return false;
                }

                char minChar = tight ? target[pos] : 'a';
                for (char c = minChar; c <= 'z'; c++) {
                    if (used[c] < halfCount[c - 'a']) {
                        curr += c;
                        used[c]++;
                        bool newTight = tight && (c == target[pos]);
                        if (backtrack(pos + 1, curr, used, newTight)) return true;
                        curr.pop_back();
                        used[c]--;
                    }
                }
                return false;
            };

        string curr = "";
        unordered_map<char, int> used;
        backtrack(0, curr, used, true);

        return result;
    }
};
