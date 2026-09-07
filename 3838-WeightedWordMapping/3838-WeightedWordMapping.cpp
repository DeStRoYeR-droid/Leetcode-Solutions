// Last updated: 07/09/2026, 22:22:56
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (const string& str : words){
            int val = 0;
            for (const char& ch : str){
                val += weights[ch - 'a'];
            }
            val = val % 26;
            result += 'a' + (25 - val);
        }
        return result;
    }
};