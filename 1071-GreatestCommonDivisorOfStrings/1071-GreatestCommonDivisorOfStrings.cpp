// Last updated: 14/09/2026, 09:29:05
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