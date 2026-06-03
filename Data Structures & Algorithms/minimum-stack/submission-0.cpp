class MinStack {
private:
    struct Node{
        int val;
        int min; // define it while adding
        Node* next;
    };
    //int min=-99999;
    Node* first = nullptr;
    //unordered_map<int,int> hash_map;

public:
    MinStack() {
        ;
    }
    
    void push(int val) {
        // Min value bookkeeping
        //int new_min = first->min;
        //if (val < first->min) new_min = val;
        int new_min = val;
        if (first != nullptr && first->min < val) new_min = first->min;
        //hash_map[val]++;
        // Linked list mechanism
        Node* neuva = new Node({val, new_min, first});
        first = neuva;
    }
    
    void pop() {
        // Min value bookkeeping - not needed
        // Linked list mechanism
        if (first==nullptr) return ;
        Node* temp = first;
        //int del_val = first->val;
        first = first->next;
        delete temp;
    }
    
    int top() {
        if (first!=nullptr) return first->val;
        else return -99999;
    }
    
    int getMin() {
        if (first!=nullptr) return first->min;
        else return -99999;
    }
};
