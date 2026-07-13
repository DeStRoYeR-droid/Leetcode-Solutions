// Last updated: 13/07/2026, 22:18:39
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        
        bool isCapitalFirst = !((word[0] - 'a') >= 0 && (word[0] - 'a') <= 26);
        bool lower = (word[1] - 'a') >= 0 && (word[1] - 'a') <= 26;

        for (int i = 1; i < word.size(); i++){
            bool curLow = (word[i] - 'a') >= 0 && (word[i] - 'a') <= 26;
            if (curLow != lower) return false;
            else if (!curLow && !isCapitalFirst) return false;
        }
        return true;
    }
};