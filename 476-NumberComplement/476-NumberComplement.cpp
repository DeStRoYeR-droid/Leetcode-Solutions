// Last updated: 13/07/2026, 22:19:12
class Solution {
public:
    int findComplement(int num) {
        int n = 1;
        while (n < num){
            n = (n << 1) | 1;
        }
        return num ^ n;
    }
};