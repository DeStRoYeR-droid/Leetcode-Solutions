// Last updated: 06/07/2026, 19:04:49
class Solution {
public:
    int maxLength(vector<string>& arr) {
        const int n = arr.size();
        vector<int> bitmap(n,0), lengths(n, 0);
        for (int i = 0; i < n; ++i){
            int mask = 0;
            for (const char& ch : arr[i]){
                if (mask & 1 << (ch - 'a')){
                    mask = -1;
                    break;
                }
                mask |= 1 << (ch - 'a');
            }
            bitmap[i] = mask;
            lengths[i] = arr[i].size();
        }
        int result = 0;
        backtrack(bitmap, lengths, 0, 0, 0, result);
        return result;
    }

    void backtrack(const vector<int>& masks, const vector<int>& lengths, int index, int currentMask, int currentLength, int& maxLen) {
        if (index == (int)masks.size()) {
            maxLen = max(maxLen, currentLength);
            return;
        }
        backtrack(masks, lengths, index + 1, currentMask, currentLength, maxLen);
    
        if (masks[index] != -1 && (currentMask & masks[index]) == 0) {
            backtrack(masks, lengths, index + 1, currentMask | masks[index], currentLength + lengths[index], maxLen);
        }
}
};