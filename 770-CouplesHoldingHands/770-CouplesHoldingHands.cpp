// Last updated: 13/07/2026, 22:16:29
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        const int n = row.size();
        vector<int> position(n, 0);

        for (int i = 0; i < n; ++i){
            position[row[i]] = i;
        }

        int result = 0; // Swaps

        for (int i = 0; i < n; i += 2){
            int curr = row[i];
            int partner = curr ^ 1;

            if (row[i + 1] == partner){
                continue;
            }
 
            int partnerPos = position[partner];

            swap(row[i + 1], row[partnerPos]);
            result += 1;

            position[row[partnerPos]] = partnerPos;
            position[row[i + 1]] = i + 1;
        }
        return result;
    }
};