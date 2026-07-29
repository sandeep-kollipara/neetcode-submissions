class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        vector<string> result;
        while (i<words.size()) {
            // Maintain a queue with words within maxWidth size
            int q_width=0;
            deque<string> q;
            while (i<words.size() and q_width<=maxWidth+1) {
                q.push_back(words[i]+' ');
                q_width+=(words[i].size()+1);
                i++;
            }
            if (q_width>maxWidth+1) {
                q.pop_back();
                i--;
                q_width-=(words[i].size()+1);
            }
            cout << q.size() << endl;
            // Dispense the extra space from left to right and generate the string
            int extra_space = maxWidth+1-q_width, gap = 0;
            if (q.size()>1) gap = extra_space/(q.size()-1);
            //cout << gap << endl;
            if (q.size()>1) extra_space = extra_space%(q.size()-1);
            //cout << extra_space << endl;
            if (i==words.size()) {
                gap = 0;
                extra_space = 0;
            }
            string justify, temp;
            while (!q.empty()) {
                temp = q.front();
                q.pop_front();
                if (!q.empty()) {
                    for (int j=0; j<gap; j++) temp+=' ';
                    if (extra_space) {
                        temp+=' ';
                        extra_space--;
                    }
                }
                justify+=temp;
            }
            justify = justify.substr(0, justify.length()-1);
            while (justify.length() < maxWidth) justify+=' '; 
            result.push_back(justify);
        }
        /*if (result[result.size()-1].length()<maxWidth) {
            string t = result[result.size()-1];
            while(t.size()<maxWidth) t+=' ';
            result[result.size()-1] = t;
        }*/
        return result;
    }
};