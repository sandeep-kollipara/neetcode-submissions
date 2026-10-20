class Solution {
    struct TrieNode {
        char c;
        bool endOfWord;
        vector<TrieNode*> alphabets;
        TrieNode(char a): c(a), alphabets(26,nullptr), endOfWord(false) {}
    };
public:
    vector<vector<int>> indexPairs(string text,vector<string>& words) {
        TrieNode* root = new TrieNode('\0');
        for (string s: words) {
            TrieNode* curr = root;
            for (char c: s) {
                if (curr->alphabets[c-'a']==nullptr) {
                    TrieNode* neuva = new TrieNode(c);
                    curr->alphabets[c-'a'] = neuva;
                }
                curr = curr->alphabets[c-'a'];
            }
            curr->endOfWord=true;
        }
        TrieNode* curr;
        vector<vector<int>> res;
        int start = 0;//, end = 0;
        for (int i=0; i<text.size(); i++) {
            curr = root;
            start = i;
            vector<int> ends;
            while (i<text.size() 
            and curr->alphabets[text[i]-'a']) {
                curr = curr->alphabets[text[i]-'a'];
                if (curr->endOfWord) ends.push_back(i);
                i++;
            }
            //end = i-1;
            for (int end: ends) if (start<=end) res.push_back({start, end});
            i = start;
        }
        return res;
    }
};
