// Last updated: 06/07/2026, 18:59:24
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