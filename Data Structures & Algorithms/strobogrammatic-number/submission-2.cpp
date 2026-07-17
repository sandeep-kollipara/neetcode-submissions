class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> hashmap;
        hashmap['0'] = '0';
        hashmap['1'] = '1';
        hashmap['6'] = '9';
        hashmap['9'] = '6';
        hashmap['8'] = '8';
        int i=0, j=num.length()-1;
        while (i<j) {
            if (hashmap[num[i]]!=num[j]) return false;
            i++;
            j--;
        }
        if (num.length()%2 and num[i]!='0' and num[i]!='1' and num[i]!='8') return false;
        return true;
    }
};
