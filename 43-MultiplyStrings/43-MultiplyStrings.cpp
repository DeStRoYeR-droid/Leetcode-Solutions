// Last updated: 13/07/2026, 22:29:28
class Solution {
public:
    string multiply(string num1, string num2) {
        const int n = num1.size();
        const int m = num2.size();
        vector<int> result(n + m + 1, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n; i++){
            int n1 = num1[i] - '0';

            for (int j = 0; j < m; j++){
                int n2 = num2[j] - '0';
                int cur = result[i + j] - '0';
                int index = i + j;
                result[index] = (result[index] + (n1 * n2));
                result[index + 1] += result[index] / 10;
                result[index] = result[index] % 10;
            }
        }
        for (int i = 0; i < result.size(); i++){
            if (result[i] >= 10){
                result[i+1] += result[i] / 10;
                result[i] = result[i] % 10;
            }
        }
    
        reverse(result.begin(), result.end());
        int index = 0;
        while (index < result.size() && result[index] == 0) index++;
        string res;
        while (index < result.size()){
            res += '0' + result[index];
            index++;
        }
        return res == "" ? "0" : res;
    }
};