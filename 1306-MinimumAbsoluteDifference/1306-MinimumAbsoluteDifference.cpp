// Last updated: 06/07/2026, 19:05:07
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        int result_value = INT_MAX;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 1; ++i){
            if (arr[i + 1] - arr[i] == result_value){
                result.push_back({arr[i], arr[i + 1]});
            }
            else if (arr[i + 1] - arr[i] < result_value){
                result_value = arr[i + 1] - arr[i];
                result.clear();
                result.push_back({arr[i], arr[i + 1]});
            }
        }

        return result;
    }
};