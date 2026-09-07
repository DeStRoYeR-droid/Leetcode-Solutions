// Last updated: 07/09/2026, 22:28:29
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int prev = 0;
        int result = 0;
        
        for (int w : weight){
            if (w < prev){
                ++result;
                prev = 0;
            }
            else prev = w;
        }

        return result;
    }
};