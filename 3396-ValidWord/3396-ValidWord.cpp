// Last updated: 06/07/2026, 18:53:12
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        static const string vowels = "AEIOUaeiou";
        bool hasConsonants = false, hasVowels = false;
        for (const char& ch : word){
            if (isalnum(ch)){
                if (isdigit(ch)) continue;
                else{
                    if (vowels.find(ch) != string::npos) hasVowels = true;
                    else hasConsonants = true;
                }
            }
            else return false;
        }
        return hasConsonants && hasVowels; 
    }
};