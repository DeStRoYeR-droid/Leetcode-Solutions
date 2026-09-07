// Last updated: 07/09/2026, 22:52:17
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for (const string& op : operations){
            if (op == "++X" || op == "X++") ++result;
            else --result;
        }
        return result;
    }
};