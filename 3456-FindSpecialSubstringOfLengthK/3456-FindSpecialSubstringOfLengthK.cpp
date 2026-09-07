// Last updated: 07/09/2026, 22:32:53
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        const int n = s.size();
        int count = 0;
        char prev = s[0];
        
        for (const char& ch : s){
            if (ch == prev) count++;
            else{
                if (count == k) return true;
                count = 1;
                prev = ch;
            }
        }
        return count == k;
    }
};