// Last updated: 02/08/2026, 14:10:55
class Solution {
public:
    int minimumPushes(string word) {
        return (word.size() - 4 * (word.size() / 8)) * (word.size() / 8 + 1);
    }
};