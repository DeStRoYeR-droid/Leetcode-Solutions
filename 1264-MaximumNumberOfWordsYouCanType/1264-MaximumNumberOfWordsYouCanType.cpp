// Last updated: 06/07/2026, 19:05:24
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        
        stringstream ss(text);
        string word;
        vector<string> words;
        while(ss >> word){
            words.push_back(word);
        }

        int result = 0;
        for (const auto& word : words){
            bool canType = true;
            for (const char& ch : word){
                if (broken.find(ch) != broken.end()){
                    canType = false;
                    break;
                }
            }
            result += canType;
        }
        return result;
    }
};