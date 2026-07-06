// Last updated: 06/07/2026, 18:49:04
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> result;
        for (const int& val : order){
            int index = binarySearch(friends, val);
            if (index != -1){
                result.push_back(friends[index]);
            }
        }
        return result;
    }
    int binarySearch(const vector<int>& arr, const int& val){
        int left = 0, right = arr.size() - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (arr[mid] == val) return mid;
            else if (arr[mid] > val) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};