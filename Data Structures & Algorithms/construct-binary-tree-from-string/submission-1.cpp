class Solution {
public:
    TreeNode* str2tree(string s) {
        auto string2tree=[](auto&& self, string s) -> TreeNode* {
            if (s=="") return nullptr;
            int count=0;
            string a, b1, b2, temp;
            for (char c: s) {
                if (c=='(' and count==0) { // external open
                    if (a=="") a = temp;
                    //else b1 = temp;
                    temp = "";
                    count++;
                } else if (c==')' and count==1) { // external close
                    if (b1=="") b1 = temp;
                    else b2 = temp;
                    temp = "";
                    count--;
                } else if (c=='(') { // internal open
                    temp+=c;
                    count++;
                } else if (c==')') { // internal close
                    temp+=c;
                    count--;
                } else temp+=c;
            }
            if (a=="") a = temp; // if only the parent is available
            //cout << a << " " << b1 << " " << b2 << endl;
            TreeNode* node = new TreeNode(stoi(a));
            if (b1!="") node->left = self(self, b1);
            if (b2!="") node->right = self(self, b2);
            return node;
        };
        return string2tree(string2tree, s);
    }
};
