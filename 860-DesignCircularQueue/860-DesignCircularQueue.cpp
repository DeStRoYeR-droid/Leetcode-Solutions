// Last updated: 06/07/2026, 19:07:57
class MyCircularQueue {
    int size;
    int front, rear;
    int maxCapacity;
    vector<int> q;
public:
    MyCircularQueue(int k) : size(0) {
        this->maxCapacity = k;
        q = vector<int>(k);
        this->front = 0;
        this->rear = 0;
    }
    
    bool enQueue(int value) {
        if (this->size == this->maxCapacity) return false;
        q[rear] = value;
        rear = (rear + 1) % maxCapacity;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if (this->size == 0) return false;
        front = (front + 1) % maxCapacity;
        --size;
        return true;
    }
    
    int Front() {
        if (this->size != 0) return q[front];
        else return -1;
    }
    
    int Rear() {
        if (this->size == 0) return -1;
        int lastIndex = (rear - 1 + maxCapacity) % maxCapacity;
        return q[lastIndex];
    }
    
    bool isEmpty() {
        return this->size == 0;
    }
    
    bool isFull() {
        return this->size == this->maxCapacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */