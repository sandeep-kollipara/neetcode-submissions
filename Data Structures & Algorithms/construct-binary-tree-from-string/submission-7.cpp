class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s=="") return nullptr; // edge case
        stack<TreeNode*> stk;
        int i=0, start=0, end=0;
        while (i<s.length() and s[i]!='(') {
            end=i;
            i++;
        }
        //cout << s.substr(start,end-start+1) << " ";
        TreeNode* nouveau = new TreeNode(stoi(s.substr(start,end-start+1)));
        stk.push(nouveau);
        start=i+1;
        while (i<s.length()) {
            // push to stack if encountered '('
            if (s[i]=='(' and start<=end) { // first term - parent
                //cout << s.substr(start,end-start+1) << " ";
                TreeNode* nouveau = new TreeNode(stoi(s.substr(start,end-start+1)));
                if (not stk.top()->left) stk.top()->left=nouveau;
                else if (not stk.top()->right) stk.top()->right=nouveau;
                stk.push(nouveau);
                start=i+1;
            }
            else if (s[i]=='(' and start>end) {
                start=i+1;
            }
            // pop off stack and attach to tree (left first, right next) if encountered ')'
            else if (s[i]==')' and start<=end) { // second and third term - children
                //cout << s.substr(start,end-start+1) << " ";
                TreeNode* nouveau = new TreeNode(stoi(s.substr(start,end-start+1)));
                if (not stk.top()->left) stk.top()->left = nouveau;
                else if (not stk.top()->right) stk.top()->right = nouveau;
                start=i+1;
            }
            else if (s[i]==')' and start>end) {
                stk.pop();
                start=i+1;
            }
            // upkeep
            else end=i;
            i++;
        }
        return stk.top();
    }
};
