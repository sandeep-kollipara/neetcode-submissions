/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr; // edge case
        unordered_map<Node*, Node*> hash_map; // global var
        function<Node*(Node*)> dfs_copy_graph_node=[&](Node* original) {
            Node* copy = new Node(original->val);
            hash_map[original]=copy;
            vector<Node*> copy_connections;
            for (Node* neighbour: original->neighbors) {
                if (hash_map.find(neighbour)==hash_map.end()) {
                    copy_connections.push_back(dfs_copy_graph_node(neighbour));
                }
                else {
                    copy_connections.push_back(hash_map[neighbour]);
                }
            }
            copy->neighbors = copy_connections;
            return copy;
        };
        return dfs_copy_graph_node(node);
    }
};
