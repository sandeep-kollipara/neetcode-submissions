class Solution {
public:
    string decodeString(string s) {
        function<string(int, string)> recurse=[&](int k, string encoded_string) {
            string base, parse;
            int i=0, brackets=0;
            string num;
            while (i < encoded_string.size()) {
                char letter = encoded_string[i];
                if (letter >= 48 and letter <= 57) num+=letter; // numeric
                else if (letter=='[') { // bracket open
                    brackets++;
                    i++;
                    while (true) {
                        if (encoded_string[i]==']' and brackets==1) {
                            brackets--;
                            break;
                        } else if (encoded_string[i]=='[') brackets++;
                        else if (encoded_string[i]==']') brackets--;
                        parse+=encoded_string[i];
                        i++;
                    }
                    base+=recurse(stoi(num), parse);
                    num="";
                    parse="";
                }
                else base+=letter; // alphabet
                i++;
            }
            string final;
            for (int i=0; i<k; i++) final+=base;
            return final;
        };
        return recurse(1, s);
    }
};