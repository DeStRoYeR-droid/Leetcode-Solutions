// Last updated: 13/07/2026, 22:19:47
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        int result = 0;
        while (ss){
            string cur;
            ss >> cur;
            ++result;
        }
        return result - 1;
    }
};