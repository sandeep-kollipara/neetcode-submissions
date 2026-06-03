class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> hash_map;
        hash_map['\0'] = -1;
        for (int i=0; i<order.size(); i++) hash_map[order[i]] = i; 
        struct TrieNode{
            char c;
            unordered_map<char,TrieNode*> dict;
            char highest_c;
            TrieNode() : c('\0'), dict({}), highest_c('\0') {}
        };
        TrieNode* init = new TrieNode();
        for (string word: words) {
            TrieNode* node = init;
            for (char b: word) {
                cout << b << endl;
                TrieNode* neuva;
                // update highest_c or break
                if (hash_map[node->highest_c] <= hash_map[b]) node->highest_c = b;
                else return false;
                // connect prev to the new
                if (node->dict.find(b)==node->dict.end()) {
                    neuva = new TrieNode();
                    neuva->c = b;
                    node->dict[b] = neuva;
                }
                else neuva = node->dict[b];
                node = neuva;
            }
            if (node->highest_c!='\0') return false;
        }
        return true;
    }
};