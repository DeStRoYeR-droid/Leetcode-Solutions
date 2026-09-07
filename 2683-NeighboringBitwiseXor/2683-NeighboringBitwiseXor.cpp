// Last updated: 07/09/2026, 22:42:04
class Solution {
public:
    bool doesValidArrayExist(const vector<int>& derived) {
        return (accumulate(derived.begin(), derived.end(), 0, bit_xor<int>()) == 0);
    }
};