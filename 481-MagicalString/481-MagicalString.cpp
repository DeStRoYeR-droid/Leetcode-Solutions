// Last updated: 13/07/2026, 22:19:07
class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;
        vector<int> arr(n, 0);
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 2;

        int head = 2, num = 1, tail = 3, result = 1;

        while (tail < n){
            for (int i = 0; i < arr[head] && tail < n; ++i){
                arr[tail] = num;
                if (num == 1) ++result;
                ++tail;
            }
            num = 3 - num; 
            ++head;
        }
        return result;
    }
};