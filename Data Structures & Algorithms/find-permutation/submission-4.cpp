class Solution {
public:
    vector<int> findPermutation(string s) {
        int max=1, stacc=0, base;
        vector<int> vec;
        if (s[0]=='I') vec.push_back(1);
        else {
            stacc++;
            max=0;
        }
        for (char c: s) {
            if (c=='I') {
                base = max;
                max = base + stacc;
                if (stacc==1) {
                    int temp = vec.back();
                    vec.pop_back();
                    vec.push_back(base+stacc);
                    vec.push_back(temp);
                    stacc--;
                } else {
                    while (stacc) {
                        vec.push_back(base+stacc);
                        //cout << base+stacc << " ";
                        stacc--;
                    }
                }
                max++;
                //cout << max << " ";
                vec.push_back(max);
            } else {
                if (stacc==0) {
                    vec.pop_back();
                    max--;
                    stacc++;
                }
                stacc++;
            }
        }
        base = max;
        max = base + stacc;
        if (stacc==1) {
            int temp = vec.back();
            vec.pop_back();
            vec.push_back(base+stacc);
            vec.push_back(temp);
            stacc--;
        } else {
            while (stacc) {
                vec.push_back(base+stacc);
                //cout << base+stacc << " ";
                stacc--;
            }
        }
        //for (int i=0; i<vec.size(); i++) vec[i]+=(-min+1);
        return vec;
    }
};
