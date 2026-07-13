// Last updated: 13/07/2026, 22:25:32
class MinStack {
private:
    stack<vector<int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minVal = getMin();
        if (st.empty() || minVal > val){
            minVal = val;
        }
        st.push({val, minVal});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.empty() ? -1 : st.top()[0];
    }
    
    int getMin() {
        return st.empty() ? -1 : st.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */