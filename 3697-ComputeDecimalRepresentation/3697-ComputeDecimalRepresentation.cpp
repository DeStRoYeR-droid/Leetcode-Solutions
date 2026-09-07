// Last updated: 07/09/2026, 22:26:22
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> result;
        string str = to_string(n);
        reverse(str.begin(), str.end());
        for (int i = 0; i < str.size(); ++i){
            if (str[i] != '0'){
                result.push_back((str[i] - '0') * pow(10, i));
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};