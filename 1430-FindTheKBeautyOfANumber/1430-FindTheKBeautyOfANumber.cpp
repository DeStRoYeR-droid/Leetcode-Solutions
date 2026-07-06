// Last updated: 06/07/2026, 19:04:20
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string number = to_string(num);
        const int n = number.size();
        int result = 0;
        for (int i = 0; i < n - k + 1; ++i){
            int val = stoi(number.substr(i, k));
            if (val == 0) continue;
            else result += (num % val == 0);
        }
        return result;
    }
};