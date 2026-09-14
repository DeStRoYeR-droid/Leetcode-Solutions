// Last updated: 14/09/2026, 09:28:44
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = arr.size() - 1;
        int j = arr.size() - 1; 
        while (i > 0){
            if (arr[i - 1] == 0){
                j = arr.size() - 1;
                while (j > i){
                    arr[j] = arr[j - 1];
                    j--;
                }
                arr[j] = 0;
            }
            i--;
        }
    }
};