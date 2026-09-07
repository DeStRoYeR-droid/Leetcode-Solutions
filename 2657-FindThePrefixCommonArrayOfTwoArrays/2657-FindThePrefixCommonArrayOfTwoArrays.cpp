// Last updated: 07/09/2026, 22:42:09
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        bitset<50> stateA = 0;
        bitset<50> stateB = 0;
        const int len = A.size();
        vector<int> result(len);
        for (int i = 0; i < len; i++){
            stateA[A[i]] = true;
            stateB[B[i]] = true;
            result[i] = (stateA & stateB).count();
        }
        return result;
    }
};