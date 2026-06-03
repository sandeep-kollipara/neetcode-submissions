class Solution {
public:
    string convertToTitle(int columnNumber) {
        string out;
        do{
            out=char((columnNumber-1)%26+65)+out;
            columnNumber=(columnNumber-1)/26;
        }while(columnNumber>0);
        return out;
    }
};