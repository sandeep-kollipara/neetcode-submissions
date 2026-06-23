/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root==nullptr) return root;
        // bfs - right to left
        queue<Node*> q;
        q.push(root);
        int level=-1, remaining=0;
        Node* prev = nullptr;
        while (!q.empty()) {
            if (remaining==0) {
                level++;
                remaining = pow(2, level);
                prev = nullptr;
            }
            Node* curr = q.front();
            if (curr->right!=nullptr) q.push(curr->right);
            if (curr->left!=nullptr) q.push(curr->left);
            curr->next = prev;
            prev = curr;
            remaining--;
            q.pop();
        }
        return root;
    }
};