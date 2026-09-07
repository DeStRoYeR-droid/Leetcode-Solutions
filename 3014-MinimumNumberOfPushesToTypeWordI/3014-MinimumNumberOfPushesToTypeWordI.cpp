// Last updated: 07/09/2026, 22:38:54
class Solution {
public:
    int minimumPushes(string word) {
        return (word.size() - 4 * (word.size() / 8)) * (word.size() / 8 + 1);
    }
};