// Last updated: 06/07/2026, 18:54:20
class Solution {
public:
    int minChanges(string& s) {
        const int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i+=2)
            result += (s[i] != s[i+1]);
        
        return result;
    }
};