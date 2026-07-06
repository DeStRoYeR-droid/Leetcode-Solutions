// Last updated: 06/07/2026, 19:02:34
class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low) / 2 + ((low % 2) || (high % 2));;
    }
};