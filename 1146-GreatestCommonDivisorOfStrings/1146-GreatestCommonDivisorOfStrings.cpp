// Last updated: 06/07/2026, 19:05:52
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 == str2 + str1){
            int index = gcd(str1.size(), str2.size());
            return str1.substr(0, index);
        }
        return "";
    }
};