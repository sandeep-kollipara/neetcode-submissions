class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int a=arr[0], n=arr.size()+1, d=(arr[arr.size()-1]-a)/(n-1);
        /*cout << "a " << a << endl;
        cout << "d " << d << endl;
        cout << "n " << n << endl;*/
        auto ar=[&](int i) {
            return a+(i-1)*d;
        };
        /*int i=1;
        while (i<=n) {
            cout << ar(i) << " ";
            i++;
        }*/
        int l=0, r=n-2, m=l+(r-l)/2;
        while (l<=r) {
            if (ar(m+1)==arr[m]) l=m+1;
            else if (ar(m+1)!=arr[m]) r=m-1;
            m=l+(r-l)/2;
        }
        //while(ar(m+1)==arr[m]){
        //    m++;
        //}
        //return ar(m+1);
        return ar(m+1);
    }
};
