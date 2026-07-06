// Last updated: 06/07/2026, 19:06:04
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        const vector<int> target = charCount(chars);
        vector<int> cur(26, 0);
        int result = 0;
        bool isPossible;
        for (const string& word : words){
            cur = charCount(word);
            isPossible = true;
            for (int i = 0; i < 26; ++i){
                if (target[i] < cur[i]){
                    isPossible = false;
                    break;
                }
            }

            result += isPossible ? word.size() : 0;
        }
        return result;
    }

    vector<int> charCount(const string& word){
        vector<int> result(26, 0);
        for (const char& ch : word) result[ch - 'a']++;
        return result;
    }
};