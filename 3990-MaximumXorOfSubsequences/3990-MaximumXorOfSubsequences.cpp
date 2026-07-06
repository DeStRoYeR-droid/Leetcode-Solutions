// Last updated: 06/07/2026, 18:49:17
class Solution {
public:
    int maxXorSubset(vector<int>& arr){
        int index = 0, n = arr.size();
        for (int bit = 31; bit >= 0; --bit){
            int use = -1;

            for (int j = index; j < n; ++j){
                if ((arr[j] & 1 << bit) && (use == -1 || arr[j] > arr[use])){
                    use = j;
                }
            }

            if (use == -1) continue;
            else swap(arr[index], arr[use]);

            for (int j = 0; j < n; ++j){
                if (j != index && (arr[j] & 1 << bit)) {
                    arr[j] ^= arr[index];
                }
            }
            ++index;
        }

        int result = 0;
        for (int x : arr){
            result ^= x;
        }
        return result;
    }
    int maxXorSubsequences(vector<int>& nums) {
        return maxXorSubset(nums);
    }
};