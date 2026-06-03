class Solution {
public:
    string predictPartyVictory(string senate) {
        int radiant=0, dire=0, r, d;
        queue<char> q1, q2;
        for (char c: senate) {
            if (c=='R') radiant++;
            else dire++;
            q1.push(c);
        }
        while (radiant>0 and dire>0) {
            r = 0, d = 0;
            while (!q1.empty()) {
                char c = q1.front();
                q1.pop();
                if (c=='R' and r==0) {
                    q2.push(c);
                    d++;
                } else if (c=='R' and r>0) {
                    radiant--;
                    r--;
                } else if (c=='D' and d==0) {
                    q2.push(c);
                    r++;
                } else if (c=='D' and d>0) {
                    dire--;
                    d--;
                }
            }
            while (!q2.empty()){
                char c = q2.front();
                q2.pop();
                if (c=='R' and r>0) {
                    radiant--;
                    r--;
                } else if (c=='D' and d>0) {
                    dire--;
                    d--;
                } else {
                    q1.push(c);
                }
            }
        }
        if (radiant) return "Radiant";
        return "Dire";
    }
};