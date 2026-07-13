// Last updated: 13/07/2026, 22:22:47
class MyStack {
    queue<int> q;
    int size;
public:
    MyStack() {
        this->size = 0;
    }
    
    void push(int x) {
        q.push(x);
        ++size;
    }
    
    int pop() {
        for (int i = 0; i < size - 1; ++i){
            int val = q.front(); q.pop();
            q.push(val);
        }
        int result = q.front(); q.pop();
        --size;
        return result;
    }
    
    int top() {
        for (int i = 0; i < size - 1; ++i){
            int val = q.front(); q.pop();
            q.push(val);
        }
        int result = q.front();
        q.pop();
        q.push(result);
        return result;
    }
    
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */