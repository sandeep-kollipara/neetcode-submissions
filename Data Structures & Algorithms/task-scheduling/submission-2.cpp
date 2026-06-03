class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        struct Triad {
            char task;
            int frequency;
            int cooldown;

            // Constructor for placeholder
            Triad() : task(' '), frequency(0), cooldown(0) {}

            // Constructor with validation
            Triad(char a, int b, int c) : task(a), frequency(b), cooldown(c) {}

            // Method to display the triad
            void display() const {
                cout << "(" << task << ", " << frequency << ", " << cooldown << ")\n";
            }
        };
        auto comparator=[](Triad left, Triad right) { // max heap frequency, min heap cooldown (reversed)
            if (left.frequency < right.frequency) return true;
            else if (left.frequency > right.frequency) return false;
            else return (left.cooldown > right.cooldown);
        };
        priority_queue<Triad, vector<Triad>, decltype(comparator)> pq(comparator);
        unordered_map<char, int> hash_map = {};
        for (int i=0; i<tasks.size(); i++) {
            if (hash_map.find(tasks[i])==hash_map.end()) hash_map[tasks[i]] = 1;
            else hash_map[tasks[i]]++;
        }
        for (auto i: hash_map) pq.push(Triad(i.first, i.second, 0));
        int cycles = 0;
        while (not pq.empty()) {
            cycles++;
            /*Triad next_task = pq.top();*/
            Triad next_task;
            vector<Triad> cooldown_list = {};
            while (not pq.empty()) {
                next_task = pq.top();
                pq.pop();
                if (next_task.cooldown > cycles) cooldown_list.push_back(next_task);
                else break;
            }
            for (int i=0; i<cooldown_list.size(); i++) pq.push(cooldown_list[i]);
            cout << next_task.task << pq.size() << endl;
            // if cooldown of next task is not zero
            if (next_task.cooldown > cycles) continue;
            // else process it
            else ; //pq.pop();
            // update task with more occurences i.e. delta = n+1
            if (next_task.frequency!=1) pq.push(Triad(next_task.task, next_task.frequency-1, cycles+n+1));
            // end of all similar tasks
            else ;
        }
        return cycles;
    }
};
