// Last updated: 06/07/2026, 18:57:06
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool isFlush = true, pair = false;
        for (int i = 1; i < 5; ++i) {
            if (suits[i] != suits[0]){
                isFlush = false;
                break;
            }
        }

        if (isFlush) return "Flush";

        vector<int> mapping(13, 0);
        for (const int& val : ranks) mapping[val - 1]++;

        for (int i = 0; i < 13; ++i){
            if (mapping[i] >= 3) return "Three of a Kind";
            if (mapping[i] == 2) pair = true;
        }
        if (pair) return "Pair";

        return "High Card";
    }
};