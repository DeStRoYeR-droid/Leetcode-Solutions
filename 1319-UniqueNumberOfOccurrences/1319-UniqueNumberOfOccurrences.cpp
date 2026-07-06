// Last updated: 06/07/2026, 19:05:02
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurences;
        for (int& num : arr){
            if (occurences.find(num) == occurences.end()) occurences[num] = 0;
            else occurences[num]++;
        }

        bool uniques[1000] = {0};
        for (auto& iter : occurences){
            if (uniques[iter.second] == 0) uniques[iter.second] = 1; 
            else return false;
        }

        return true;
    }
};