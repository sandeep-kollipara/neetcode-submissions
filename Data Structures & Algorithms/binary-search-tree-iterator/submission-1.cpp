/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    /*stack<TreeNode*> stk;*/
    /*deque<TreeNode*> dq;*/
    stack<pair<TreeNode*,bool>> stk;
public:
    BSTIterator(TreeNode* root) {
        /*stk.push(root);
        while(stk.size() and stk.top()->left) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }*/
        /*dq.push_front(root);
        while(dq.size() and dq.front()->left) {
            TreeNode* node = dq.front();
            if (node->right) dq.push_back(node->right);
            if (node->left) dq.push_front(node->left);
        }*/
        stk.push({root,false});
        cout << "Iterator: ";
        while (stk.size()) {
            TreeNode* node = stk.top().first;
            bool status = stk.top().second;
            if (not status) {
                stk.pop();
                if (node->right) stk.push({node->right,false});
                stk.push({node,true});
                if (node->left) stk.push({node->left,false});
            } else break;
            cout << node->val << " ";
        }
    }
    
    int next() {
        /*if (stk.size()) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
            return node->val;
        }
        return -1;*/
        /*if (dq.size()) {
            TreeNode* node = dq.front();
            dq.pop_front();
            if (node->right) dq.push_back(node->right);
            if (node->left) dq.push_front(node->left);
            return node->val;
        }
        return -1;*/
        bool status = false;
        while (stk.size() and not status) {
            TreeNode* node = stk.top().first;
            status = stk.top().second;
            stk.pop();
            if (not status) {
                if (node->right) stk.push({node->right,false});
                stk.push({node,true});
                if (node->left) stk.push({node->left,false});
            } else {
                return node->val;
            }
        }
        return -1;
    }
    
    bool hasNext() {
        /*return (stk.size()>1 or 
        (stk.size() and stk.top()->right));*/
        /*return (dq.size()>1 or 
        (dq.size() and dq.front()->right));*/
        return (stk.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */