class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s=="") return nullptr; // edge case
        stack<TreeNode*> stk;
        int i=0;
        string r;
        while (i<s.length() and s[i]!='(') {
            r+=s[i];
            i++;
        }
        TreeNode* nouveau = new TreeNode(stoi(r));
        stk.push(nouveau);
        r="";
        while (i<s.length()) {
            // push to stack if encountered '('
            if (s[i]=='(' and r!="") { // first term - parent
                TreeNode* nouveau = new TreeNode(stoi(r));
                if (not stk.top()->left) stk.top()->left=nouveau;
                else if (not stk.top()->right) stk.top()->right=nouveau;
                stk.push(nouveau);
                r="";
            }
            else if (s[i]=='(' and r=="") {
                ;
            }
            // pop off stack and attach to tree (left first, right next) if encountered ')'
            else if (s[i]==')' and r!="") { // second and third term - children
                TreeNode* nouveau = new TreeNode(stoi(r));
                if (not stk.top()->left) stk.top()->left = nouveau;
                else if (not stk.top()->right) stk.top()->right = nouveau;
                r="";
            }
            else if (s[i]==')' and r=="") {
                stk.pop();
            }
            // upkeep
            else r+=s[i]; 
            i++;
        }
        return stk.top();
    }
};
