// Last updated: 13/07/2026, 22:24:48
bool compare(const int& a, const int& b){
    string sa = to_string(a), sb = to_string(b);

    if ((sa + sb) > (sb + sa)) return true;
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        
        if (nums[0] == 0) return "0";
        string s = accumulate(nums.begin(), nums.end(), string(""), 
            [](const string& a, int b) {
                return a + to_string(b);
            }
        );

        return s;
    }
};
