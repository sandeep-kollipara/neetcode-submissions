class SnakeGame {
    int h, w;
    queue<pair<int,int>> q = {}; // snake is reverse queue
    pair<int,int> goal = {-1,-1};
    int size = 1;
    vector<vector<int>> food_locs;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w = width;
        h = height;
        q.push({0,0});
        goal = {food[0][0], food[0][1]};
        food_locs = food;
        food_locs.push_back({-2,-2}); // unreachable point at the end
    }
    
    int move(string direction) {
        pair head = q.back();
        /*switch(direction) {
            case "U":
                head.first++;
                break;
            case "D":
                head.first++;
                break;
            case "L":
                head.second--;
                break;
            case "R":
                head.second--;
                break;
            default:
                return -1;
        }*/
        if (direction=="U") head.first--;
        else if (direction=="D") head.first++;
        else if (direction=="L") head.second--;
        else if (direction=="R") head.second++;
        else return -1;
        //cout << head.first << "," << head.second << endl;
        // die when self eaten
        for (int i=0; i<q.size(); i++) { //i<size; i++) {
            if (q.front()==head) return -1;
            q.push(q.front());
            q.pop();
        }
        // out of bounds
        if (head.second < 0 or head.second >= w 
        or head.first < 0 or head.first >= h) return -1;
        // advance
        if (q.size()==size) q.pop();
        q.push(head);
        //q.pop();
        //if (q.back()!=goal) q.pop();
        // grow when food is eaten
        if (q.back()==goal) {
            size++;
            goal = {food_locs[size-1][0], food_locs[size-1][1]};
        }
        /*if (q.back()!=goal) q.pop();
        else {
            size++;
            goal = {food_locs[size-1][0], food_locs[size-1][1]};
        }*/
        cout << "(" << q.back().first << "," << q.back().second << ") - (" << q.front().first << "," << q.front().second << ")" << endl;
        return size-1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
