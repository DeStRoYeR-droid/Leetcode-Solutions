// Last updated: 06/07/2026, 19:08:38
class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (const int& num : nums){
            if (heap.size() < k) heap.push(num);
            else if (num > heap.top()){
                heap.push(num);
                if (heap.size() > k) heap.pop();
            }
        }        
    }
    
    int add(int val) {
        if (heap.size() < k) heap.push(val);
        else if (val > heap.top()){
            heap.push(val);
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */