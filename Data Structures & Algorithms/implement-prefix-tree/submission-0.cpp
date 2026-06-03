struct TrieNode {
    // properties
    char ch;
    unordered_map<char,pair<TrieNode*, bool>> hash_map;

    // methods
    void update(char c, TrieNode* child, bool eos) {
        this->hash_map[c] = pair<TrieNode*, bool>({child, eos});
    }

    pair<TrieNode*, bool> find(char c) {
        if (this->hash_map.find(c)==this->hash_map.end()) return pair<TrieNode*, bool>({nullptr, false});
        else return this->hash_map[c];
    }

    // constructor 1 - creates empty properties (suitable for root/nodes in PrefixTree)
    TrieNode() : ch('\0'), hash_map({}) {}

    // constructor 2 - assigns one child node (useful in bottom-up construction but unused)
    TrieNode(char c, TrieNode* child, bool eos) {
        this->ch = c;
        this->hash_map[c] = pair<TrieNode*, bool>({child, eos});
    }
};

class PrefixTree {
public:
    // Properties
    TrieNode root;

    // Constructor
    PrefixTree() {
        // initialize root (empty)
    }

    // Methods
    void insert(string word) {
        TrieNode* node = &this->root;
        for (int i=0; i<word.length(); i++) {
            if (node->hash_map.find(word[i])==node->hash_map.end()) { // not present
                // create new node - prefinal and final [PREFINAL CARRIES THE BOOL FOR EOS]
                TrieNode* neuva = new TrieNode();
                if (i!=word.length()-1) node->update(word[i], neuva, false);
                else node->update(word[i], neuva, true);
                node = neuva;
            }
            else{ // present
                // traverse the root until the end or last match
                TrieNode* next = node->hash_map[word[i]].first;
                if (i==word.length()-1) node->update(word[i], next, true);
                node = next;
            }
        }
    }
    
    bool search(string word) {
        // search if present with last check
        TrieNode* node = &this->root;
        for (int i=0; i<word.length(); i++) {
            pair<TrieNode*, bool> map_result =  node->find(word[i]);
            TrieNode* next = map_result.first;
            bool last = map_result.second;
            if (next!=nullptr and i==word.length()-1 and last) return true;
            else if (next!=nullptr) node = next;
            else return false;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        // search if present without last check
        TrieNode* node = &this->root;
        for (int i=0; i<prefix.length(); i++) {
            pair<TrieNode*, bool> map_result =  node->find(prefix[i]);
            TrieNode* next = map_result.first;
            if (next!=nullptr and i==prefix.length()-1) return true;
            else if (next!=nullptr) node = next;
            else return false;
        }
        return false;
    }
};