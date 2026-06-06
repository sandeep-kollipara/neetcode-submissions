class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        auto cmp=[](pair<int,char> a, pair<int,char> b) { // max heap
            return a.first < b.first;
        };
        priority_queue<pair<int,char>, vector<pair<int,char>>, decltype(cmp)> pq(cmp);
        if (a > 0) pq.push(make_pair(a,'a'));
        if (b > 0) pq.push(make_pair(b,'b'));
        if (c > 0) pq.push(make_pair(c,'c'));
        char last_char='\0', d, d2;
        string happy="";
        int count, count2;
        bool double_pop=false;
        while (!pq.empty()){
            count = pq.top().first;
            d = pq.top().second;
            pq.pop();
            if (last_char==d and pq.size()==0) {
                pq.push(make_pair(count,d));
                break;
            }else if (last_char==d) {
                double_pop=true;
                count2 = count;
                d2 = d;
                //cout << "2x pop " << d2 << " " << count2 << endl;
                count = pq.top().first;
                d = pq.top().second;
                pq.pop();
            }
            /*if (count>1 and pq.size()>0) {
                happy+=d;
                happy+=d;
                count--;
            } else happy+=d;*/
            happy+=d;
            count--;
            if (double_pop) pq.push(make_pair(count2,d2));
            if (count > 0) pq.push(make_pair(count,d));
            last_char = d;
            double_pop = false;
            cout << d << " " << count << endl;
        }
        if (pq.size() > 0) {
            count = pq.top().first;
            d = pq.top().second;
        } else count = 0;
        int i=0;
        while(count>0 and i<happy.length()){
            if (happy[i]==d){
                happy.insert(happy.begin()+i, d);
                i++;
                count--;
            }
            i++;
        }
        cout << "pq size:" << pq.size() << endl;
        return happy;
    }
};