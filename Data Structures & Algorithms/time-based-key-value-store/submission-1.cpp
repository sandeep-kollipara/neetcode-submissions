class TimeMap {
private:
    unordered_map<string,vector<pair<string,int>>> hash_table;

public:
    TimeMap() {
        hash_table = {};
    }
    
    void set(string key, string value, int timestamp) { // assume all are increasing order
        if (hash_table.find(key)!=hash_table.end()) {
            vector<pair<string,int>> table = hash_table[key];
            table.push_back({value,timestamp});
            hash_table[key] = table;
        }
        else hash_table[key] = vector<pair<string,int>>({pair<string,int>({value,timestamp})});
    }
    
    string get(string key, int timestamp) {
        if (hash_table.find(key)!=hash_table.end()) {
            vector<pair<string,int>> table = hash_table[key];
            int low=0, high=table.size()-1, mid;
            while (high-low>1) {
                mid = ceil((low+high)/2);
                if (table[mid].second > timestamp) high = mid;
                else if (table[mid].second < timestamp) low = mid;
                else return table[mid].first;
            }
            if (table[high].second <= timestamp) return table[high].first;
            else if (table[low].second <= timestamp) return table[low].first;
            else return ""; // no values
        }
        else return "";
    }
};
