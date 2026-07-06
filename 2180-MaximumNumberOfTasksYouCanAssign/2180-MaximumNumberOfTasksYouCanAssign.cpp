// Last updated: 06/07/2026, 18:59:05
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size());
        while (left < right){
            int mid = (left + right + 1) / 2;
            int used = 0;

            multiset<int> free(workers.end() - mid, workers.end());

            bool canAssign = true;
            for (int i = mid - 1; i >= 0; --i){
                auto it = prev(free.end());

                if (*it < tasks[i]){
                    it = free.lower_bound(tasks[i] - strength);
                    if (it == free.end()){
                        canAssign = false;
                        break;
                    }

                    ++used;
                    if (used > pills){
                        canAssign = false;
                        break;
                    }
                }

                free.erase(it);
            }
            if (canAssign) left = mid;
            else right = mid - 1;
        }

        return left;
    }
};