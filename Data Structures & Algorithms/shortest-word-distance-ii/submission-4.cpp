class WordDistance {
    unordered_map<string,vector<int>> hashmap;
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i=0; i<wordsDict.size(); i++) {
            hashmap[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto bin_search=[&](vector<int>& arr, int find){
            int l=0, r=arr.size()-1, m=l+(r-l)/2;
            while (l<r) {
                if (arr[m]<find) l=m+1;
                else if (arr[m]>find) r=m-1;
                else return m;
                m = l+(r-l)/2;
            }
            return l;
            if (l+1<arr.size() and abs(arr[l+1]-find) < abs(arr[l]-find)) return l+1;
            else if (l-1<arr.size() and abs(arr[l-1]-find) < abs(arr[l]-find)) return l-1;
            return l;
        };
        if (hashmap.find(word1)!=hashmap.end() and hashmap.find(word2)!=hashmap.end()) {
            vector<int> a = hashmap[word1], b = hashmap[word2];
            int min_distance=INT_MAX;
            // Brute Force - O(n^2)
            //for (auto i: a) for (auto j: b) min_distance = min(min_distance, abs(i-j));
            // Binary Search - O(nlogn)
            /*for (int i=0; i<a.size(); i++) {
                int dist = abs(b[bin_search(b, a[i])]-a[i]);
                min_distance = min(min_distance, dist);
            }*/
            // Two pointers - O(n)
            int i=0, j=0;
            while (i<a.size() and j<b.size()) {
                // update
                min_distance = min(min_distance, abs(a[i]-b[j]));
                // traversal
                if (a[i]<b[j]) i++;
                else j++;
            }
            //return abs(hashmap[word1] - hashmap[word2]);
            return min_distance;
        }
        return -1;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
