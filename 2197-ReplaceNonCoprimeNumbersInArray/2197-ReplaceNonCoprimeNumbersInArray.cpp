// Last updated: 07/09/2026, 22:48:40
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for (const int num : nums){
            result.push_back(num);
            while (result.size() > 1){
                int a = result[result.size() - 1];
                int b = result[result.size() - 2];

                int g = gcd(a, b);
                if (g > 1){
                    result.pop_back();
                    result.pop_back();

                    long long lcm = (long long) a / g * b;
                    result.push_back(int(lcm));
                }
                else break;
            }
        }
        return result;
    }
};