// Last updated: 13/07/2026, 22:18:49
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<std::pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> maxheap;
        int i = 0;
        for (int j = 0; j < k; ++j){
            while (i < n && projects[i].first <= w){
                maxheap.push(projects[i].second);
                ++i;
            }

            if (maxheap.empty()) break;
            w += maxheap.top(); maxheap.pop();
        }
        return w;
    }
};