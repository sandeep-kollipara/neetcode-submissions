class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1; // edge case
        function<vector<int>(int)> int_to_bin=[](int i){
            int rem=i;
            vector<int> bin;
            for (int j=10; j>-1; j--) { // 11 bits
                bin.push_back(rem/pow(2,j)); // left to right
                rem = rem % (int)pow(2,j);
            }
            return bin;
        };
        vector<int> bin_n = int_to_bin(abs(n));
        for (int i: bin_n) cout << i << " ";
        cout << endl;
        if (n < 0) x = 1/x; // takes care of negative powers
        double j=1.0, power=1;
        while (bin_n.size()!=0){
            int exp = bin_n[bin_n.size()-1];
            bin_n.pop_back();
            j*=j;
            if (j==1) j=x;
            if (exp) power*=j;
        }
        return power;
    }
};
