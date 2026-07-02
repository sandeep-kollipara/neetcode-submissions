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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push((Node*)nullptr);
        string s;
        while (!q.empty()){
            Node* node = q.front();
            if (node==nullptr) {
                s+="_";
                s+=",";
                q.pop();
            } else {
                s+=to_string(node->val);
                s+=",";
                q.pop();
                for (auto child: node->children) q.push(child);
                q.push((Node*)nullptr);
            }    
        }
        return s;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        queue<Node*> q;
        string s;
        for (char c: data) {
            if (c!=',') s+=c;
            else {
                Node* neuva;
                if (s!="_") neuva = new Node(stoi(s));
                else neuva = (Node*)nullptr;
                q.push(neuva);
                s="";
            }
        }
        Node *root = q.front();
        q.pop();
        if (q.front()==nullptr) q.pop();
        vector<Node*> parents = {root};
        while (!q.empty()) {
            vector<Node*> next_level;
            for (auto node: parents) {
                vector<Node*> offsprings;
                while(q.front()!=nullptr) {
                    offsprings.push_back(q.front());
                    q.pop();
                }
                if (q.front()==nullptr) q.pop();
                node->children = offsprings;
                next_level.insert(next_level.end(),offsprings.begin(), offsprings.end());
            }
            parents = next_level;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
