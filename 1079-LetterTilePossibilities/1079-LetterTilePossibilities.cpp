// Last updated: 14/09/2026, 09:28:48
class Solution {
public:
    int numTilePossibilities(string& tiles) {
        unordered_map<char, int> freq;
        for (const char& ch : tiles) freq[ch]++;
        int count = 0;
        backtrack(freq, count);
        return count;
    }

    void backtrack(unordered_map<char, int>& remaining, int& count){
        for (auto& charFreq : remaining){
            if (charFreq.second > 0){
                charFreq.second--;
                count++;
                backtrack(remaining, count);
                charFreq.second++;

            }
        }
    }
};