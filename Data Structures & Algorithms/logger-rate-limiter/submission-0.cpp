class Logger {
    unordered_map<string, int> hashmap;
public:
    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (hashmap.size() and hashmap.find(message)!=hashmap.end() and timestamp < hashmap[message] + 10){
            return false;
        }
        hashmap[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
