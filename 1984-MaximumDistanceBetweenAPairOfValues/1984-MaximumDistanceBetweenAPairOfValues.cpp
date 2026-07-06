// Last updated: 06/07/2026, 19:00:30
class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i, j;
        for (i = 0, j = 0; i < A.size() && j < B.size(); j++)
            i += A[i] > B[j];
        return max(0, j - i - 1);
    }
};