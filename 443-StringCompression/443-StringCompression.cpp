// Last updated: 13/07/2026, 22:19:36
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return 1;
        int index = 0;
        int tracker = 0;
        char cur = chars[0];
        int count = 0;
        string s;
        while (tracker < chars.size()){
            if (chars[tracker] == cur){
                count++;
            }
            else {
                chars[index++] = cur;
                cur = chars[tracker];
                
                if (count > 1){
                    s = to_string(count);
                    for (char& ch : s) chars[index++] = ch;
                }
                count = 1;
            }
            tracker++;
        }
        
        chars[index++] = cur;        
        if (count > 1){
            s = to_string(count);
            for (char& ch : s) chars[index++] = ch;
        }
        
        return index;
    }
};