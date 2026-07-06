// Last updated: 06/07/2026, 19:00:04

class Solution {
public:
    int countTriples(int n) {
        const static vector<int> vals = {5, 13, 17, 25, 29, 37, 41, 53, 61, 65, 65, 73, 85, 85, 89, 97, 101, 109, 113, 125, 137, 145, 145, 149, 157, 169, 173, 181, 185, 185, 193, 197, 205, 205, 221, 221, 229, 233, 241};
        int result = 0;
        for (const auto& val : vals){
            result += n / val;
        }
        return result << 1;
    }
};