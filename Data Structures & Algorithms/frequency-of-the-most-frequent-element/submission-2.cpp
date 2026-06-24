class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // calculate existing frequency
        unordered_map<int,int> hashmap;
        for (int i: nums) hashmap[i]++;
        // for every element, search k units above and below and update frequency - O(k*n)
        int max_freq=0;
        for (int i: nums) {
            int thres=k, j=1, curr=hashmap[i], freq;
            //check above and (not) below
            while (j<=thres) {
                /*if (hashmap.find(i+j)!=hashmap.end()) {
                    freq = hashmap[i+j];
                    while (thres>0 and freq>0) {
                        thres-=j;
                        curr++;
                        freq--;
                    }
                    if (thres<=0) {
                        if (thres<0) curr--;
                        break;
                    }
                }*/
                if (hashmap.find(i-j)!=hashmap.end()) {
                    freq = hashmap[i-j];
                    while (thres>0 and freq>0) {
                        thres-=j;
                        curr++;
                        freq--;
                    }
                    if (thres<=0) {
                        if (thres<0) curr--;
                        break;
                    }
                }
                j++;
            }
            max_freq = max(curr, max_freq);
        }
        return max_freq;
    }
};