// Last updated: 06/07/2026, 18:50:40
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int n = fruits.size();
        int result = 0;

        for (int i = 0; i < n; ++i){
            bool placed = false;
            for (int j = 0; j < n; ++j){
                if (baskets[j] >= fruits[i]){
                    placed = true;
                    baskets[j] = -1;
                    break;
                }
            }
            if (!placed) ++result;
        }
        
        return result;
    }
};