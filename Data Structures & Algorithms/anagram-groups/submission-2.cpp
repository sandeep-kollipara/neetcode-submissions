class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<char, int> array_hashmaps[1000];
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            for (char c: str){
                if(array_hashmaps[i].find(c) != array_hashmaps[i].end()){
                    array_hashmaps[i][c]++;
                }
                else{
                    /*array_hashmaps[i][(char)0]=1;*/ /* initialization '\0'*/
                    array_hashmaps[i][c]=1;
                }
            }
        }
        cout << "array_hashmap created" << endl;
        vector<vector<string>> out_list = {};
        /*vector<string>*/ vector<int> master_list = {};
        int u = 0;
        while(u!=strs.size()){
            if (find(master_list.begin(), master_list.end(), u) != master_list.end()){/*strs[u]) != master_list.end()){*/
                u++;
                cout << "External loop " << u << "continued" << endl;
                continue;
            }
            master_list.insert(master_list.end(), u); /*strs[u]);*/
            vector<string> uv_list = {strs[u]};
            int v = 0;
            while (v!=strs.size()){
                if (find(master_list.begin(), master_list.end(), v) != master_list.end()){/*strs[v]) != master_list.end()){*/
                    v++;
                    cout << "Internal loop " << v << "continued" << endl;
                    continue;
                }
                if (array_hashmaps[u]==array_hashmaps[v]){
                    master_list.insert(master_list.end(), v); /*strs[v]);*/
                    uv_list.insert(uv_list.end(), strs[v]);
                }
                v++;
                cout << "Internal loop " << v << "concluded" << endl;
            }
            out_list.insert(out_list.end(), uv_list);
            u++;
            cout << "External loop " << u << "concluded" << endl;
        }
        return out_list;
    }
};