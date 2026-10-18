class Solution {
public:
    string largestOddNumber(string num) {
        int del_count=0;
        for (auto i=num.end()-1; i>=num.begin(); i--) {
            del_count++;
            if ((*i-48)%2==1) {
                del_count--;
                break;
            }
        }
        for (int i=0; i<del_count; i++) num.pop_back();
        return num;
    }
};
