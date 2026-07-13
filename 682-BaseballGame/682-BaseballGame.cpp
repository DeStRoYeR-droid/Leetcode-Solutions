// Last updated: 13/07/2026, 22:17:17
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> result;
        for (const string& str : operations){
            if (str == "C"){
                result.pop_back();
            }
            else if (str == "D"){
                result.push_back(result[result.size() - 1] * 2);
            }
            else if (str == "+"){
                int lastVal = result[result.size() - 1];
                int lastVal2 = result[result.size() - 2];
                result.push_back(lastVal + lastVal2);
            }
            else result.push_back(stoi(str));
        }
        return accumulate(result.begin(), result.end(), 0);
    }
};