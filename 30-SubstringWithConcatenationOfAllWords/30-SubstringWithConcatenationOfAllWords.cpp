// Last updated: 13/07/2026, 22:29:50
class Solution {
public:
    bool checkSubstring(unordered_map<string, int> wordCount, string s, int wordLen){
        for (int j = 0; j < s.size(); j += wordLen){
            string w = s.substr(j, wordLen);
            if (wordCount.find(w) != wordCount.end()){
                if (--wordCount[w] == -1){
                    return false;
                }
            }
            else return false;
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordLen = words[0].size();
        int sLen = s.size();
        int wordsWindow = words.size() * wordLen;

        unordered_map<string, int> wordCount;
        for (int i = 0; i < words.size(); i++) wordCount[words[i]]++;

        int i = 0;
        while (i + wordsWindow <= sLen){
            if (checkSubstring(wordCount, s.substr(i, wordsWindow), wordLen)){
                result.push_back(i);
            }
            i++;
        }
        return result;
    }
};