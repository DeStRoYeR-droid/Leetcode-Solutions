// Last updated: 13/07/2026, 22:28:33
class Solution {
public:
    string simplifyPath(string path) {
        const int n = path.size();
        deque<string> container;
        
        int i = 0;
        while (i < n){
            if (path[i] == '/'){
                i++;
                string cur = "";
                while (i < n && path[i] != '/'){
                    cur += path[i];
                    i++;
                }
                if (cur == "" || cur == ".") continue;
                if (cur == ".."){
                    if (!container.empty()) container.pop_back();
                }
                else container.push_back(cur);
            }
        }

        string result = "/";
        while (!container.empty()){
            result += container.front();
            container.pop_front();
            if (!container.empty()) result += '/';
        }
        return result;
    }
};