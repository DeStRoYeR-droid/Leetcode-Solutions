// Last updated: 13/07/2026, 22:17:24
class Solution {
public:
    int maximumSwap(int num) {
        int* arr = new int[9];
        int n = num, index = 0;
        while (n != 0){
            arr[index++] = n % 10;
            n = n / 10;
        }
        for (int i = index - 1; i >= 0; i--){
            int max_index = -1;
            int max_num = INT_MIN;
            for (int j = i - 1; j >= 0; j--){
                if (arr[j] >= max_num){
                    max_index = j;
                    max_num = arr[j];
                }
            }
            if (max_num > arr[i]){
                swap(arr[max_index], arr[i]);
                int result = 0;
                for (int k = index - 1; k >= 0; k--){
                    result *= 10;
                    result += arr[k];
                }
                return result;
            }
        }
        return num;
    }
};