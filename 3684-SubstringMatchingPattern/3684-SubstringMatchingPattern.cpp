// Last updated: 06/07/2026, 18:51:25
class Solution {
public:
    bool hasMatch(string s, string p) {
        int star = p.find('*');
        string pref = p.substr(0 , star);
        string suff = p.substr(star + 1);

        int i = s.find(pref);
        int j = s.rfind(suff);

        return i != -1 && j != -1 && i + pref.size() <= j;
    }
};