class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> hash_set;
        unordered_map<int,int> hash_map;
        int sum=0;
        for (vector<int> edge: trust) {
            if (hash_set.find(edge[0])==hash_set.end()){
                hash_set.insert(edge[0]);
                sum+=edge[0];
            }
            hash_map[edge[1]]++;
        }
        int town_judge = (n*(n+1)/2)-sum;
        if (hash_map[town_judge]==n-1) return town_judge;
        return -1;
        /*if (sum==(n*(n+1)/2)) return -1;
        else {
            int town_judge = (n*(n+1)/2)-sum;
            if (hash_map.find(town_judge)!=hash_map.end() 
            and hash_map[town_judge]==n-1) return town_judge;
            else return -1;
        }*/
    }
};