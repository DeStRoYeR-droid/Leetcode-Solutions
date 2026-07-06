// Last updated: 06/07/2026, 19:07:34
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> nums(arr.begin(), arr.end());
        const int n = arr.size();
        int result = 0;

        for (int i = 0; i < n - 2; i++){
            for (int j = i + 1; j < n - 1; j++){
                int cur = 0;
                if (nums.find(arr[i] + arr[j]) != nums.end()){
                    int n1 = arr[i];
                    int n2 = arr[j];
                    cur = 2;
                    while (nums.find(n1 + n2) != nums.end()){
                        int temp = n2;
                        n2 = n1 + n2;
                        n1 = temp;
                        cur++;
                    }
                }
                result = max(result, cur);
            }
        }
        return result;
    }
};