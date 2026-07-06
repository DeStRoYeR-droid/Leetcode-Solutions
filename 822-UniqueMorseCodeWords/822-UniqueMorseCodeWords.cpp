// Last updated: 06/07/2026, 19:08:15
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static const vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> codes;
        for (const auto& word : words){
            string cur = "";
            for (const char& ch : word) cur += code[ch - 'a'];
            codes.insert(cur);
        }
        return codes.size();
    }
};