// Last updated: 06/07/2026, 18:58:40
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        for (const string& word : words) mpp[word]++;
        int count = 0, pali = 0;

        for (auto& [word, freq] : mpp){
            string s = word;
            reverse(s.begin(), s.end());
            if (word == s){
                count+= (freq / 2) * 4;
                if (freq % 2) pali = 1;
            }
            else if (word < s && mpp.count(s)){
                count += min(freq, mpp[s]) * 4;
            }
        }

        return count + pali * 2;
    }
};