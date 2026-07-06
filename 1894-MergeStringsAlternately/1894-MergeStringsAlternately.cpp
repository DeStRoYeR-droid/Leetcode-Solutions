// Last updated: 06/07/2026, 19:00:53
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int index_1 = 0, index_2 = 0;
        bool turn = 1;
        while (index_1 < word1.length() && index_2 < word2.length()){
            result += (turn) ? word1[index_1++] : word2[index_2++];
            turn = !turn;
        }
        while (index_1 < word1.length()) result += word1[index_1++];
        while (index_2 < word2.length()) result += word2[index_2++];
        return result;
    }
};