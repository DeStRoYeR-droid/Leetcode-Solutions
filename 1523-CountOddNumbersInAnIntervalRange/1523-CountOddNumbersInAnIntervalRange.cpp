// Last updated: 14/09/2026, 09:20:52
class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low) / 2 + ((low % 2) || (high % 2));;
    }
};