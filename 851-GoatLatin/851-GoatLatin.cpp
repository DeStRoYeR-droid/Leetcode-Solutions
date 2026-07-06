// Last updated: 06/07/2026, 19:08:05
class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string result;
        string curEnd = "a";
        string word;
        while (ss >> word){
            result += transform(word) + curEnd;
            curEnd += "a";
            result += " ";
        }
        result = result.substr(0, result.size() - 1);
        return result;
    }
    string transform(string& word){
        static const string vowels = "AEIOUaeiou";
        if (vowels.find(word[0]) != string::npos)
            return word + "ma";
        else 
            return word.substr(1) + word[0] + "ma";
    }
};