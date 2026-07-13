// Last updated: 13/07/2026, 22:17:55
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        const int size = flowerbed.size();
        for (int i = 0; i < size; i++){
            if (flowerbed[i]) continue;
            bool left = (i == 0) || (flowerbed[i-1] == 0);
            bool right = (i == size - 1) || (flowerbed[i + 1] == 0);
            
            if (left && right){
                flowerbed[i] = 1;
                n -= 1;
            }
        }
        return (n <= 0);
    }
};