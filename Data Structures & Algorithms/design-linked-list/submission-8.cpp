class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node() : val(0), next(nullptr) {}
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    int capacity = 0;
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        //cout << "\ncapacity="<< capacity;
        if (index >= capacity) return -1;
        else {
            int i = 0;
            Node* node = head;
            while (i < index) {
                node = node->next;
                i++;
            }
            return node->val;
        }
    }
    
    void addAtHead(int val) {
        Node* neuva = new Node();
        neuva->val = val;
        neuva->next = head;
        head = neuva;
        if (capacity == 0) tail = head;
        capacity++;
    }
    
    void addAtTail(int val) {
        Node* neuva = new Node();
        neuva->val = val;
        if (tail!=nullptr) tail->next = neuva;
        tail = neuva;
        if (capacity == 0) head = tail;
        capacity++;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) addAtHead(val);
        else if (index == capacity) addAtTail(val);
        else if (index > 0 and index < capacity) {
            int i = 0;
            Node* node = head;
            while(i < index - 1) {
                node = node->next;
                i++;
            }
            Node* neuva = new Node();
            neuva->val = val;
            neuva->next = node->next;
            node->next = neuva;
            capacity++;
        } else return ;
        //capacity++;
    }
    
    void deleteAtIndex(int index) {
        Node* temp;
        if (index == 0) {
            temp = head;
            head = head->next;
            if (capacity == 1) tail = nullptr;
            delete temp;
        } else if (index > 0 and index < capacity) {
            int i = 0;
            Node* node = head;
            while(i < index - 1) {
                node = node->next;
                i++;
            }
            temp = node->next;
            if (index != capacity - 1) node->next = node->next->next;
            else {
                node->next = nullptr;
                tail = node;
            }
            delete temp;
        } else {
            cout << "Out of range error" << endl;
            return ;}
        capacity--;
        /*cout << "\ncapacity="<< capacity << endl;
        Node* kwelp = head;
        while (kwelp!=nullptr) {
            cout << " " << kwelp->val;
            kwelp = kwelp->next;
        }
        cout << endl;*/
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */