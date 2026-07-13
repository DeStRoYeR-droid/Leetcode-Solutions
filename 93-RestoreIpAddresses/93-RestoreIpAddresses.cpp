// Last updated: 13/07/2026, 22:27:46
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        helper(s, 4, "", result);
        return result;
    }

    void helper(string s, int blocks, string cur, vector<string>& result){
        if (s.size() > blocks * 3) return;
        if (s.size() == 0 && blocks > 0) return;
        if (blocks == 0 && s == ""){
            cur.pop_back();
            result.push_back(cur);
        }
        int val = 0;
        string copyCur = cur;
        for (int i = 0; i < min((int)s.size(), 3); ++i){
            if (i > 0 && val == 0) break;
            val = val * 10 + (s[i] - '0');
            if (val < 256){
                string next = copyCur +  to_string(val);
                next += '.';
                helper(s.substr(i + 1), blocks - 1, next, result);
                next.pop_back();
            }
        }
    }
};

/*
"101023"

["1.0.1.23","1.0.10.23","1.0.102.3","1.1.0.23","1.1.2.3","1.10.2.3","10.1.0.23","10.1.2.3","10.10.2.3","101.0.2.3"]

["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/