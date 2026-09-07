// Last updated: 07/09/2026, 22:40:02
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); ++i){
            if (words[i].find(x) != string::npos) result.push_back(i);
        }
        return result;
    }
};