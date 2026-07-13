// Last updated: 13/07/2026, 22:29:43
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearchBegin(nums, target), binarySearchEnd(nums, target)};
    }

    int binarySearchBegin(const vector<int>& arr, const int target){
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (arr[mid] > target) right = mid - 1;
            else if (arr[mid] < target) left = mid + 1;
            else{
                if (mid == 0) return mid;
                else if (arr[mid - 1] == target) right = mid - 1;
                else return mid;
            }
        }
        return - 1;
    }

    int binarySearchEnd(const vector<int>& arr, const int target){
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (arr[mid] > target) right = mid - 1;
            else if (arr[mid] < target) left = mid + 1;
            else{
                if (mid == arr.size() - 1) return mid;
                else if (arr[mid + 1] == target) left = mid + 1;
                else return mid;
            }
        }
        return - 1;
    }
};