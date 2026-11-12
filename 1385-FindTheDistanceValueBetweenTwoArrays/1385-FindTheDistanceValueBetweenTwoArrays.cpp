// Last updated: 12/11/2026, 23:08:12
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int result = 0;
        for (const int& i : arr1){
            bool add = true;
            for (const int& j : arr2){
                if (abs(i - j) <= d){
                    add = false;
                    break;
                }
            }
            result += add;
        }
        return result;
    }
};