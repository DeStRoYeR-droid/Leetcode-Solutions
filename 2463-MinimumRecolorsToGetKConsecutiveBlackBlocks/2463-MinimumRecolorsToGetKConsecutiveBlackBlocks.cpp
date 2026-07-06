// Last updated: 06/07/2026, 18:56:56
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        int i;
        for (i = 0; i < k; i++){
            count += (blocks[i] == 'W');
        }
        int result = count;
        int left = 0;
        for (i; i < blocks.size(); i++){
            count += (blocks[i] == 'W') - (blocks[left] == 'W');
            left++;
            result = min(result, count);
        }
        return result;
    }
};