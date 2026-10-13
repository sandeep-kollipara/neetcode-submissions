class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        //vector<int> wait_time(customers.size());
        long total_wait_time=0;
        int chef_available=0, i=0;
        for (auto v: customers) {
            int waiting=0;
            if (chef_available > v[0]) {
                waiting = chef_available - v[0];
                chef_available+=v[1];
            } else {
                chef_available=v[0]+v[1];
            }
            //wait_time[i] = waiting+v[1];
            total_wait_time+=waiting+v[1];
            i++;
        }
        //for (auto i: wait_time) cout << i << " ";
        //return (double)accumulate(wait_time.begin(), wait_time.end(), 0)/wait_time.size();
        return (double)total_wait_time/customers.size();
    }
};