// Last updated: 13/07/2026, 22:30:49
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bitset<256> bset;
        int i = 0 , j = 0, maxLength = 0;
        while(j<s.size()){
            if(bset[int(s[j])] == 1){
                while(s[i] != s[j]){
                    bset[s[i]] = 0;
                    i++;
                }
                i++;
            }
            else{
                bset[int(s[j])] = 1;
            }
            j++;
            if(j-i > maxLength) maxLength = j-i;
        }
        return maxLength;
        
    }
};