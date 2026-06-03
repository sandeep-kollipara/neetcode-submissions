class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int>arr_shift = arr;
        arr_shift.insert(arr_shift.begin(), arr_shift[0]);
        arr.push_back(arr[arr.size()-1]);
        for (int i=0; i<arr.size(); i++) {
            arr_shift[i] = arr[i] - arr_shift[i];
        }
        /*if (arr_shift[0]*arr_shift[1]<0) arr_shift[0] = -arr_shift[0];
        if (arr_shift[arr_shift.size()-2]*arr_shift[arr_shift.size()-1]<0) {
            arr_shift[arr_shift.size()-1] = -arr_shift[arr_shift.size()-1];
        }*/
        int length = 0, max_length=0;
        bool prev_zero=false, prev_positive=true;
        for (int i=0; i<arr_shift.size(); i++) {
            if (arr_shift[i]<0) {
                if (prev_zero) length=1;
                else if (!prev_zero and prev_positive) length++;
                else if (!prev_zero and !prev_positive) length=1;
                prev_zero=false;
                prev_positive=false;
            } else if (arr_shift[i]==0) {
                if (prev_zero) length=0;
                else if (!prev_zero and prev_positive) length=0;
                else if (!prev_zero and !prev_positive) length=0;
                prev_zero=true;
                prev_positive=false;
            } else if (arr_shift[i]>0) {
                if (prev_zero) length=1;
                else if (!prev_zero and prev_positive) length=1;
                else if (!prev_zero and !prev_positive) length++;
                prev_zero=false;
                prev_positive=true;
            }
            if (length > max_length) max_length = length;
            if (prev_zero) length=0;
        }
        return max_length+1;
    }
};