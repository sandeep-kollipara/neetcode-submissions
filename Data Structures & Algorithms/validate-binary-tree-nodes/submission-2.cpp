class Solution {
    struct TreeNode{
        TreeNode* left, *right, *parent;
        int val;
        TreeNode(int val): left(nullptr), right(nullptr), 
        parent(nullptr), val(val) {}
    };
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<TreeNode*> nodes(n, nullptr);
        for (int i=0; i<n; i++) nodes[i] = new TreeNode(i);
        for (int i=0; i<n; i++) {
            if (leftChild[i]!=-1) {
                nodes[i]->left = nodes[leftChild[i]];
                if (not nodes[leftChild[i]]->parent) nodes[leftChild[i]]->parent = nodes[i];
                else return false;
            }
            if (rightChild[i]!=-1) {
                nodes[i]->right = nodes[rightChild[i]];
                if (not nodes[rightChild[i]]->parent) nodes[rightChild[i]]->parent = nodes[i];
                else return false;
            }
        }
        TreeNode* node=nodes[0];
        int i=0;
        while (node->parent and ++i) if(i<n) node = node->parent; else return false;
        cout << node->val;
        int sum=0;
        stack<TreeNode*> stk;
        stk.push(node);
        while (stk.size()) {
            TreeNode* node = stk.top();
            sum+=(node->val+1);
            stk.pop();
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }
        return sum==n*(n+1)/2;
    }
};
