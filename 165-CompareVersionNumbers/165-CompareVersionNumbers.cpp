// Last updated: 13/07/2026, 22:25:24
class Solution {
public:
    long long getVersion(const string& str, int& index){
        long long version = 0LL;
        if (index >= str.size()) return version;

        while (index < str.size()){
            if (str[index] == '.') break;
            else version = version * 10 + (str[index] - '0');
            ++index;
        }
        if (index < str.size() && str[index] == '.') ++index;
        return version;
    }
    int compareVersion(const string& version1, const string& version2) {
        int index1 = 0, index2 = 0;

        while (version1.size() > index1 || version2.size() > index2){
            long long curX = getVersion(version1, index1);
            long long curY = getVersion(version2, index2);

            if (curX == curY) continue;
            else if (curX > curY) return 1;
            else if (curY > curX) return -1;
        }
        return 0;
    }
};