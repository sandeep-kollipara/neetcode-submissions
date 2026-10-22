class Solution {
public:
    TreeNode* str2tree(string s) {
        auto string2tree=[&](auto&& self, int start, int length) -> TreeNode* {
            //cout << "Entering new function " << start << " " << length << endl;
            if (length==0) return nullptr;
            int count=0, b1=-1, b2=-1, end=-1, end2=-1;
            for (int i=start; i<start+length; i++) {
                char c = s[i];
                if (c=='(' and count==0) { // external open
                    if (b1==-1) b1 = i+1;
                    else if (b2==-1) b2 = i+1;
                    count++;
                } else if (c=='(') { // internal open
                    count++;
                } else if (c==')') { // external/internal close
                    count--;
                }
            }
            if (b1==-1) end = start+length-1; // if only the parent is available
            else end = b1-2;
            if (b1!=-1 and b2==-1) end2 = start+length-1; // if only 1 child is available
            else end2 = b2-2;
            // debugging statement caused the error, like what?
            //cout << s.substr(start,end-start+1) << " " << s.substr(b1, end2-b1) << " " << s.substr(b2, start+length-b2-1) << endl;
            TreeNode* node = new TreeNode(stoi(s.substr(start,end-start+1)));
            if (b1!=-1) node->left = self(self, b1, end2-b1);
            if (b2!=-1) node->right = self(self, b2, start+length-b2-1);
            return node;
        };
        return string2tree(string2tree, 0, s.length());
    }
};
