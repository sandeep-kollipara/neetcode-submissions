class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return vector<string>({});
        // initializing the hash map
        unordered_map<char, vector<string>> phone_num_letter;
        phone_num_letter['2']=vector<string>({"a","b","c"});
        phone_num_letter['3']=vector<string>({"d","e","f"});
        phone_num_letter['4']=vector<string>({"g","h","i"});
        phone_num_letter['5']=vector<string>({"j","k","l"});
        phone_num_letter['6']=vector<string>({"m","n","o"});
        phone_num_letter['7']=vector<string>({"p","q","r","s"});
        phone_num_letter['8']=vector<string>({"t","u","v"});
        phone_num_letter['9']=vector<string>({"w","x","y","z"});
        // parse the input
        vector<vector<string>> digits_to_chars;
        for (char c: digits) digits_to_chars.push_back(phone_num_letter[c]);
        // create the string combinations
        function<vector<string>(int, string)> recurse_tree=[&](int i, string s){
            if (i==digits.length()) return vector<string>({s}); // termination
            vector<string> tot, rec;
            for (string r: digits_to_chars[i]) {
                rec = recurse_tree(i+1,s+r);
                tot.insert(tot.begin(),rec.begin(),rec.end());
            }
            return tot;
        };
        return recurse_tree(0, "");
    }
};
