// Last updated: 13/07/2026, 22:29:53
class Solution {
public:
    int strStr(string haystack, string needle) {
        return (haystack.find(needle) != std::string::npos) ? haystack.find(needle) : -1;
    }
};