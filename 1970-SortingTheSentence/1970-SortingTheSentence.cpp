// Last updated: 06/07/2026, 19:00:35
class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word, result = "";
        vector<string> res(9);
        while (ss >> word){
            int index = (word[word.size() - 1] - '1');
            res[index] = word.substr(0, word.size() - 1);
        }
        for (const string& word : res){
            if (word != "") result += word + " ";
        }
        return result.substr(0, result.size() -1);
    }
};