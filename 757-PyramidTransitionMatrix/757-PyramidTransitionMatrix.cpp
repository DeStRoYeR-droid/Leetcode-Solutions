// Last updated: 13/07/2026, 22:16:39
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for (auto &s : allowed)
            mp[s.substr(0, 2)].push_back(s[2]);

        unordered_set<string> bad;

        function<bool(const string&)> dfs = [&](const string& row) -> bool {
            if (row.size() == 1) return true;
            if (bad.count(row)) return false;
            vector<string> nextRows;
            buildNextRows(row, 0, "", mp, nextRows);
            if (nextRows.empty()) {
                bad.insert(row);
                return false;
            }
            for (auto &nr : nextRows)
                if (dfs(nr)) return true;
            bad.insert(row);
            return false;
        };

        return dfs(bottom);
    }

    void buildNextRows(const string& row, int i, string cur,
                    unordered_map<string, vector<char>>& mp,
                    vector<string>& res) {
        if (i == row.size() - 1) {
            res.push_back(cur);
            return;
        }
        string key = row.substr(i, 2);
        if (!mp.count(key)) return;
        for (char c : mp[key])
            buildNextRows(row, i + 1, cur + c, mp, res);
    }
};