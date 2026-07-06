// Last updated: 06/07/2026, 18:51:20
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);
        vector<int> offlineUntil(numberOfUsers, 0);

        sort(events.begin(), events.end(), [&](auto &a, auto &b) {
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);

            if (t1 != t2) return t1 < t2;

            if (a[0] == "OFFLINE" && b[0] == "MESSAGE") return true;
            if (a[0] == "MESSAGE" && b[0] == "OFFLINE") return false;

            return false;
        });

        for (auto &ev : events) {

            string type = ev[0];
            int time = stoi(ev[1]);
            for (int u = 0; u < numberOfUsers; u++) {
                if (!online[u] && time >= offlineUntil[u]) {
                    online[u] = true;
                }
            }

            if (type == "OFFLINE") {
                int id = stoi(ev[2]);
                online[id] = false;
                offlineUntil[id] = time + 60;

            } else {
                string msg = ev[2];

                if (msg == "ALL") {
                    for (int u = 0; u < numberOfUsers; u++) ans[u]++;
                } 
                else if (msg == "HERE") {
                    for (int u = 0; u < numberOfUsers; u++) {
                        if (online[u]) ans[u]++;
                    }

                } 
                else {
                    stringstream ss(msg);
                    string part;

                    while (ss >> part) {
                        int id = stoi(part.substr(2));

                        ans[id]++;
                    }
                }
            }
        }

        return ans;
    }
};