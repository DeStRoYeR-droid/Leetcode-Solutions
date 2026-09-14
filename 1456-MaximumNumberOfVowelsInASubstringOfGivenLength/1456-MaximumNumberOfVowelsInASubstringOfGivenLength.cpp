// Last updated: 14/09/2026, 09:21:59
class Solution {
public:
    int maxVowels(string s, int k) {
        const int len = s.size();
        int index = 0;
        int result = 0;
        int bitmap = (1 << ('u' - 'a')) | (1 << ('o' - 'a')) | (1 << ('i' - 'a')) | (1 << ('e' - 'a')) | 1;

        while (index < k){
            if ((1 << s[index] - 'a') & bitmap) result++;
            index++;
        }
        int cur = result;
        while (index < len){
            if ((1 << s[index] - 'a') & bitmap) ++cur;
            if ((1 << s[index-k] - 'a') & bitmap) --cur;
            result = max(result, cur);
            index++;
        }
        return result;
    }
};