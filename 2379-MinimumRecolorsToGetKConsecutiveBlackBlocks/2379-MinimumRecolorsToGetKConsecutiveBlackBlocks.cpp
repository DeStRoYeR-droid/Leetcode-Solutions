// Last updated: 07/09/2026, 22:45:59
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