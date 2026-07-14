class Solution {
public:
    bool confusingNumber(int n) {
        string m =to_string(n), p;
        for (auto a: m) {
            switch (a){
                case '0':
                    p='0'+p;
                    break;
                case '1':
                    p='1'+p;
                    break;
                case '6':
                    p='9'+p;
                    break;
                case '8':
                    p='8'+p;
                    break;
                case '9':
                    p='6'+p;
                    break;
                default:
                    return false;
            }
        }
        if (p==m) return false;
        return true;
    }
};
