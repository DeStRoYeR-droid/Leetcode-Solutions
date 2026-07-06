// Last updated: 06/07/2026, 18:51:03
class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (const char& ch : s) freq[ch - 'a']++;
        int highestOdd = 0, lowestEven = INT_MAX;
        
        for (const int& num : freq){
            if (num == 0) continue;
            
            if (num % 2 && num > highestOdd) highestOdd = num;
            else if (!(num % 2) && num < lowestEven) lowestEven = num;
        }
        return highestOdd - lowestEven;
    }
};