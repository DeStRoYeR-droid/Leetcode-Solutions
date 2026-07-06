// Last updated: 06/07/2026, 18:59:41
class Solution {
public:
    int minSwaps(string s) {
        int not_matching = 0;
        for (const char& ch : s){
            if (ch == '[') not_matching++;
            else if (not_matching)
                not_matching--;
            
        }
        return (not_matching + 1) / 2;
    }
};