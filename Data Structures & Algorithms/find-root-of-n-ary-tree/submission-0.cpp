/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        unordered_set<Node*> hashset;
        for (auto node: tree) for (auto child: node->children) hashset.insert(child);
        for (auto node: tree) if (hashset.find(node)==hashset.end()) return node;
    }
};
