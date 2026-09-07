// Last updated: 07/09/2026, 22:47:58
class Solution {
public:
    string largestGoodInteger(string num) {
        const int n = num.size();
        string result = "";
        int maxVal = -1;
        
        for (int i = 0; i < n - 2; ++i){
            if (num[i] == num[i+1] && num[i+1] == num[i + 2] && (num[i] - '0') > maxVal){
                maxVal = num[i] - '0';
                result = num.substr(i, 3);
            }
        }

        return result;
    }
};