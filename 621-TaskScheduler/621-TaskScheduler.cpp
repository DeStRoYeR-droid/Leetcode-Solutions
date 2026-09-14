// Last updated: 14/09/2026, 09:38:16
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size() == 0) return 0;

        vector<int> occur(26, 0);
        for (const char& ch : tasks) occur[ch - 'A']++;
        
        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i){
            if (occur[i]) pq.push(occur[i]);
        }

        int result = 0;
        while (!pq.empty()){
            vector<int> cur(n);
            int tasks_executed = 0;

            for (int i = 0; i < n + 1; ++i){
                if (!pq.empty()){
                    cur.push_back(pq.top() - 1);
                    pq.pop();
                    tasks_executed++;
                }
            }
            for (int freq : cur){
                if (freq > 0){
                    pq.push(freq);
                }
            }

            if (!pq.empty()){
                result += n + 1;
            }
            else {
                result += tasks_executed;
            }
        }
        return result;
    }
};