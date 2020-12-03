class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        elements.push(x);
        if(minelements.empty() || x < minelements.top())
        {
            minelements.push(x);
        }
        else 
        {
            minelements.push(minelements.top());
        }
    }
    
    void pop() {
        elements.pop();
        minelements.pop();
    }
    
    int top() {
        
        return elements.top();
        
    }
    
    int getMin() {
        return minelements.top();
        
    }
    
private:
    stack<int> elements;
    stack<int> minelements;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
