class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int minimum = *min_element(nums.begin(),nums.end());
        int sum=0;
        while (minimum){
            sum+=(minimum%10);
            minimum/=10;
        }
        cout << sum;
        return -1*(sum%2-1);
    }
};
