class Solution {
public:
    string largestGoodInteger(string num) {
        if (num.length() < 3) return "";
        unordered_set<char> hashset;
        for (int i=0; i < 3; i++) {
            hashset.insert(num[i]);
        }
        int maximum=-1;
        if (hashset.size()==1) maximum = stoi(num.substr(0,3));
        for (int i=3; i < num.length(); i++) {
            hashset.erase(num[i-3]);
            hashset.insert(num[i-2]);
            hashset.insert(num[i-1]);
            hashset.insert(num[i]);
            if (hashset.size()==1) {
                cout << num.substr(i-2,3) << endl;
                maximum = max(stoi(num.substr(i-2,3)),maximum);
            }
        }
        if (maximum==-1) return "";
        else if (maximum==0) return "000";
        else return to_string(maximum);
    }
};