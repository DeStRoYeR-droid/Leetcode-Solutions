// Last updated: 06/07/2026, 18:49:39
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