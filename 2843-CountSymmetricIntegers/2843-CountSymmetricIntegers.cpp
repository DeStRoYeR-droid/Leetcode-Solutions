// Last updated: 07/09/2026, 22:40:55
class Solution {
public:
    int countSymmetricIntegers(const int& low, const int& high) {
        int result = 0;
        for (int i = low; i <= high; ++i){
            string s = to_string(i);
            if (s.size() % 2) continue;

            int n = s.size() / 2;
            int firstHalf = 0, secondHalf = 0;
            for (int j = 0; j < n; ++j) firstHalf += (s[j] - '0');
            for (int j = n; j < s.size(); ++j) secondHalf += (s[j] - '0');

            result += (firstHalf == secondHalf);
        }
        return result;
    }
};