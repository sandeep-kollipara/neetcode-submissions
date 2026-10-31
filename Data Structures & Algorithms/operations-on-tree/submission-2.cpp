class LockingTree {
    struct TreeNode {
        TreeNode *parent;
        vector<TreeNode*> children;
        int val;
        int user;
        bool lock;
        TreeNode(int v): children({}), 
        parent(nullptr), val(v), user(-1), lock(false) {}
    };
    vector<TreeNode*> arrmap;
public:
    LockingTree(vector<int>& parent) {
        arrmap = vector<TreeNode*>(parent.size(), nullptr);
        for (int i=0; i<parent.size(); i++) {
            if (not arrmap[i]) {
                TreeNode* noveau = new TreeNode(i);
                arrmap[i] = noveau;
            }
            if (parent[i]!=-1 and not arrmap[parent[i]]) {
                TreeNode* neuva = new TreeNode(parent[i]);
                arrmap[parent[i]] = neuva;
            }
            if (parent[i]!=-1 and arrmap[parent[i]]) {
                arrmap[i]->parent = arrmap[parent[i]];
                arrmap[parent[i]]->children.push_back(arrmap[i]);
                //if (arrmap[parent[i]]->left) arrmap[parent[i]]->right = arrmap[i];
                //else arrmap[parent[i]]->left = arrmap[i];
            }
        }
    }
    bool lock(int num, int user) {
        if (not arrmap[num]->lock) {
            arrmap[num]->lock = true;
            arrmap[num]->user = user;
            return true;
        }
        return false;
    }
    bool unlock(int num, int user) {
        if (arrmap[num]->lock and arrmap[num]->user==user) {
            arrmap[num]->lock = false;
            arrmap[num]->user = -1;
            return true;
        }
        return false;
    }
    bool upgrade(int num, int user) {
        if (not arrmap[num]->lock)  {
            // ancestor check
            TreeNode* parent = arrmap[num];
            while (parent->parent) {
                parent = parent->parent;
                if (parent->lock) return false;
            }
            //cout << "ancestor check passed" << endl;
            // descendant check
            parent = arrmap[num];
            stack<TreeNode*> stk;
            stk.push(parent);
            bool desc_lock = false;
            while (not stk.empty() and not desc_lock) {
                parent = stk.top();
                stk.pop();
                //if (parent->left) stk.push(parent->left);
                //if (parent->right) stk.push(parent->right);
                for (auto& c: parent->children) stk.push(c);
                if (parent->lock) {
                    desc_lock=true;
                    break;
                }
            }
            if (not desc_lock) return false;
            //cout << "descendant check passed" << endl;
            // unlock all descendants
            parent = arrmap[num];
            stk = stack<TreeNode*>();
            stk.push(parent);
            while (not stk.empty()) {
                parent = stk.top();
                stk.pop();
                //if (parent->left) stk.push(parent->left);
                //if (parent->right) stk.push(parent->right);
                for (auto& c: parent->children) stk.push(c);
                parent->lock = false;
                parent->user = -1;
            }
            // lock the num
            arrmap[num]->lock = true;
            arrmap[num]->user = user;
            return true;
        }
        return false;
    }
};
