// Last updated: 13/07/2026, 22:22:36
class MyQueue {
private:
    stack<int> st, rev; 
public:
    MyQueue() {}
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while (!st.empty()){
            int val = st.top(); st.pop();
            rev.push(val);
        }
        int result = rev.top(); rev.pop();
        while (!rev.empty()){
            int val = rev.top(); rev.pop();
            st.push(val);
        }
        return result;
    }
    
    int peek() {
        while (!st.empty()){
            int val = st.top(); st.pop();
            rev.push(val);
        }
        int result = rev.top();
        while (!rev.empty()){
            int val = rev.top(); rev.pop();
            st.push(val);
        }
        return result;
    }
    
    bool empty() {
        return st.empty();
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