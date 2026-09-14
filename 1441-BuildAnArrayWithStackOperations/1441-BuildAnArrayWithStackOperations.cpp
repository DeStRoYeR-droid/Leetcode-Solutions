// Last updated: 14/09/2026, 09:22:17
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int tPtr = 0;
        for (int i = 0; i < n; ++i){
            if (tPtr >= target.size()) break;
            if (target[tPtr] == i + 1){
                result.push_back("Push");
                ++tPtr;
            }
            else{
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        return result;
    }
};