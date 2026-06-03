class StockSpanner {
private:
    stack<int> lifo;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        /*if (lifo.empty()) {
            lifo.push(price);
            return 0;
        }
        else {*/
            int span=1;
            stack<int> lifo2 = lifo;
            lifo.push(price);
            while (!lifo2.empty()) {
                if (lifo2.top() > price) break;
                lifo2.pop();
                span++;
            }
            return span;
        /*}*/
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */