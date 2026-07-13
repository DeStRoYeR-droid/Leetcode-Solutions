// Last updated: 13/07/2026, 22:18:50
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        static const string firstRow = "qwertyuiopQWERTYUIOP";
        static const string secondRow = "asdfghjklASDFGHJKL";
        static const string thirdRow = "zxcvbnmZXCVBNM";

        vector<string> result;
        for (const string& word : words){
            bool first = true, second = true, third = true;
            for (const char& ch : word){
                if (first && firstRow.find(ch) == string::npos) first = false;
                if (second && secondRow.find(ch) == string::npos) second = false;
                if (third && thirdRow.find(ch) == string::npos) third = false;
            }

            if (first || second || third) result.push_back(word);
        }

        return result;

    }
};