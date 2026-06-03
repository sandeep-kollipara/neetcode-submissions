class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> lifo;
        for (int i=0; i<asteroids.size(); i++) {
            if (lifo.empty()) lifo.push(asteroids[i]);
            else {
                if (asteroids[i]*lifo.top() < 0 and asteroids[i]<lifo.top()) { // opposite sign and closing in
                    if (asteroids[i] + lifo.top() == 0) lifo.pop();
                    else {
                        int neuva = lifo.top();
                        lifo.pop();
                        if (abs(neuva) > abs(asteroids[i])) asteroids[i] = neuva;
                        else ;
                        i--;
                    }
                }
                else { // same sign or opposite sign but moving away
                    lifo.push(asteroids[i]);
                }
            }
        }
        vector<int> out;
        while (!lifo.empty()) {
            out.insert(out.begin(), lifo.top());
            lifo.pop();
        }
        return out;
    }
};