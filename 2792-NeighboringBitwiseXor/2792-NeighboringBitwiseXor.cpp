// Last updated: 06/07/2026, 18:55:11
class Solution {
public:
    bool doesValidArrayExist(const vector<int>& derived) {
        return (accumulate(derived.begin(), derived.end(), 0, bit_xor<int>()) == 0);
    }
};