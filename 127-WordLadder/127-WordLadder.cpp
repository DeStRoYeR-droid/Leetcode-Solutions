// Last updated: 13/07/2026, 22:26:28
class Solution {
public:
    int ladderLength(const string beginWord, const string endWord, const vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<tuple<string, int>> q;
        q.push({beginWord, 1});

        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        while (!q.empty()){
            auto [word, level] = q.front(); q.pop();
            if (word == endWord) return level;
            for (int i = 0; i < word.size(); ++i){
                for (const char& ch : alphabet){
                    string newWord = word.substr(0, i) + ch + word.substr(i+1);
                    if (newWord == word) continue;
                    else if (words.find(newWord) != words.end() && 
                    visited.find(newWord) == visited.end()){
                        visited.insert(newWord);
                        q.push({newWord, level + 1});
                    }
                }
            }
        }
        return 0;
    }
};