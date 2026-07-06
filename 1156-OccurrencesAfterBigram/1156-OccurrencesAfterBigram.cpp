// Last updated: 06/07/2026, 19:05:49
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        stringstream ss(text);
        string word;
        while (ss >> word) words.push_back(word);

        vector<string> result;
        for (int i = 0; i < words.size() - 2; ++i){
            if (words[i] == first && words[i + 1] == second) result.push_back(words[i + 2]);
        }
        return result;
    }
};