// Last updated: 06/07/2026, 19:08:03
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedWords(banned.begin(), banned.end());
        string cur = "";
        unordered_map<string, int> freq; 

        for (const char& ch : paragraph){
            if (!isalpha(ch)){
                if (cur != ""){
                    freq[cur]++;
                }
                cur = "";
            }
            else{
                cur += ::tolower(ch);
            }
        }
        if (cur != "") freq[cur]++;

        string result = "";
        int maxF = 0;
        for (const auto& val : freq){
            if (bannedWords.find(val.first) == bannedWords.end()){
                if (maxF < val.second){
                    result = val.first;
                    maxF = val.second;
                }
            }
        }
        return result;
    }
};