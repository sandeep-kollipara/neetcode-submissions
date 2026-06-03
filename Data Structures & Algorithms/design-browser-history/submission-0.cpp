class BrowserHistory {
    vector<string> history;
    int current, max;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current = max = 0;
    }
    
    void visit(string url) {
        if (history.size() == max+1 and current == max) {
            history.push_back(url);
        } else {
            history[current+1] = url;
        }
        current++;
        max = current;
    }
    
    string back(int steps) {
        if (current - steps >= 0) {
            current = current - steps;
        } else {
            current = 0;
        }
        return history[current];
    }
    
    string forward(int steps) {
        if (current + steps <= max) {
            current = current + steps;
        } else {
            current = max;
        }
        return history[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */