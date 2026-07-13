// Last updated: 13/07/2026, 22:16:42
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> bitmap(26, 0);
        for (const char& ch : licensePlate){
            if ('A' <= ch && ch <= 'Z') bitmap[ch - 'A']++;
            else if ('a' <= ch && ch <= 'z') bitmap[ch - 'a']++;
        }

        string result = "";
        vector<int> curMap(26, 0);
        for (const string& word : words){
            curMap = vector<int>(26, 0);
            for (const char& ch : word) curMap[ch - 'a']++;
            int isValid = true;
            for (int i = 0; i < 26; ++i){
                if (bitmap[i] > curMap[i]){
                    isValid = false;
                    break;
                }
                // curMap[i] = 0;
            }

            if (isValid){
                if (result == "") result = word;
                else if (result.size() > word.size()) result = word;
            }
        }
        return result;
    }
};