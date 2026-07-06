// Last updated: 06/07/2026, 18:48:32
class ExamTracker {
private:
    vector<int> times;
    vector<long long> tree;
    int n;

    int newTreeSize(int n){
        int result = 1;
        while (result < n) result <<= 1;
        return result;
    }

    void updateTree(int position, long long val){
        position += n;
        tree[position] = val;
        position /= 2;

        while (position > 0){
            tree[position] = tree[position << 1] + tree[position << 1 | 1];
            position /= 2;
        }
    }

    long long queryTree(int left, int right){
        long long result = 0;
        left += n;
        right += n;

        while (left <= right){
            if (left & 1){
                result += tree[left];
                ++left;
            }

            if ((right & 1) == 0){
                result += tree[right];
                --right;
            }

            left >>= 1;
            right >>= 1;
        }
        return result;
    }
public:
    ExamTracker() : n(0){
        
    }
    
    void record(int time, int score) {
        times.push_back(time);

        if (tree.empty()){
            n = newTreeSize(1);
            tree.assign(2 * n, 0);
        }
        else if (times.size() > n){
            int old = n;
            n = newTreeSize(times.size());

            vector<long long> newTree(2 * n, 0);
            for (int i = 0; i < old; ++i){
                newTree[n + i] = tree[old + i];
            }

            tree = move(newTree);
            for (int i = n - 1; i > 0; --i){
                tree[i] = tree[i << 1] + tree[i << 1 | 1];
            }
        }
        updateTree(times.size() - 1, score);
    }
    
    long long totalScore(int startTime, int endTime) {
        auto leftiter = lower_bound(times.begin(), times.end(), startTime);
        auto rightiter = upper_bound(times.begin(), times.end(), endTime);

        if (leftiter == times.end() || rightiter == times.begin()) return 0;

        int leftIdx = leftiter - times.begin();
        int rightIdx = rightiter - times.begin() - 1;

        if (leftIdx > rightIdx) return 0;
        return queryTree(leftIdx, rightIdx);
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */