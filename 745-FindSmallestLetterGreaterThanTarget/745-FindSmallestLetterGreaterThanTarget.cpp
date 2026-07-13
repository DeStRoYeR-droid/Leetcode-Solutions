// Last updated: 13/07/2026, 22:16:45
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target || letters[0] > target) return letters[0];
        int low = 0;
        int hig = letters.size() - 1;
        while(low < hig){
            int mid = (low + hig + 1) / 2;
            if(letters[mid] <= target){
                low = mid;
            }
            else{
                hig = mid - 1;
            }
        }
        return letters[low + 1];
    }
};