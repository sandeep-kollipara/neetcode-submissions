class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        vector<int> answer(arrival.size(), 0);
        queue<int> entry, exit;
        auto load_person=[&](int i){
            if (state[i]) exit.push(i);
            else entry.push(i);
        };
        int time=INT_MIN, i=0;
        bool last_exit=true; // last_exit ~ last_entry
        while (i<arrival.size() or !entry.empty() or !exit.empty()) {
            // Case 1: Queues are empty
            if (entry.empty() and exit.empty()) {
                // move the time to the next arrival
                if (arrival[i]-time>0) last_exit=true;
                time = arrival[i];
                load_person(i);
                i++;
            } else { // Case 2: Queues are not empty
                // add any additional persons arriving at the same time
                while (i<arrival.size() and time>=arrival[i]) {
                    load_person(i);
                    i++;
                }
                // release person by rule and advance time
                if (last_exit and !exit.empty()) {
                    answer[exit.front()] = time;
                    exit.pop();
                } else if (last_exit and exit.empty()) {
                    answer[entry.front()] = time;
                    entry.pop();
                    last_exit = false;
                } else if (!last_exit and entry.empty()) {
                    answer[exit.front()] = time;
                    exit.pop();
                    last_exit = true;
                } else if (!last_exit and !entry.empty()) {
                    answer[entry.front()] = time;
                    entry.pop();
                }
                time++;
            }
        }
        return answer;
    }
};
