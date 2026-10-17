class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res(code);
        int i=0, j=0, sum=0;
        // initialize window
        while (j<abs(k)) {
            sum+=code[j];
            j++;
        }
        j=j%code.size();
        if (k>0) res[j]=sum;
        else if (k<0) res[code.size()-1]=sum;
        else res[i]=0;
        // sliding window
        int g=0;
        while (g++<code.size()) {
            sum-=code[i];
            int h = i;
            i++;
            i=i%code.size();
            sum+=code[j];
            j++;
            j=j%code.size();
            if (k>0) res[h]=sum;
            else if (k<0) res[j]=sum;
            else res[h]=0;
        }
        return res;
    }
};
