// Last updated: 24/08/2026, 22:41:35
class Solution {
public:
    bool sumGame(string num) {
        double ls = 0, rs = 0;
        int n = num.size();
        for (int i = 0; i < n / 2; ++i){
            if (num[i] == '?') ls += 4.5;
            else ls += (num[i] - '0');
        } 
        for (int i = n / 2; i < n; ++i){
            if (num[i] == '?') rs += 4.5;
            else rs += (num[i] - '0');   
        }

        return rs != ls;
    }
};