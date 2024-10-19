class MyQueue {
public:
    stack<int> s,k;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while(!(s.empty())){
            int a = s.top();
            s.pop();
            k.push(a);
        }
        int b = k.top();
        k.pop();
        while(!(k.empty())){
            int a = k.top();
            k.pop();
            s.push(a);
        }
        return b;
    }
    
    int peek() {
        while(!(s.empty())){
            int a = s.top();
            s.pop();
            k.push(a);
        }
        int b = k.top();
        // k.pop();
        while(!(k.empty())){
            int a = k.top();
            k.pop();
            s.push(a);
        }
        return b;
    }
    
    bool empty() {
        return s.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */