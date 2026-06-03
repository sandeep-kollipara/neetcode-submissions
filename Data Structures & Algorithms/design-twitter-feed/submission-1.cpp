class Twitter { // AI helped me with this one.
private:
    unordered_map<int,set<int>> hash_table; // user_id -> list<follower_id>
    int timer; // updates on new post (used as a key)
    typedef pair<int,pair<int,int>> feed; // (time ,(user_id, tweet_id))
    /*auto comparator=[](feed left, feed right) {
        return left.first <  right.first;
    };*/
    class Comparator {
    public:
        bool operator()(feed a, feed b){
            return a.first < b.first;
        }
    };
    priority_queue<feed, vector<feed>, Comparator /*decltype(comparator)*/> pq; // stores the feed in max heap by time

public:
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        feed neuva = {timer, {userId, tweetId}};
        pq.push(neuva);
        if (hash_table.find(userId)==hash_table.end()) hash_table[userId]=set<int>({});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> feed_search;
        feed_search.insert(userId);
        if (hash_table.find(userId)!=hash_table.end()) {
            set<int> followees = hash_table[userId];
            for (set<int>::iterator it=followees.begin(); it!=followees.end(); it++) {
                feed_search.insert(*it);
            }
        }
        //else return vector<int>({});
        stack<feed> s;
        vector<int> newsfeed;
        while (newsfeed.size()<10 and pq.size()!=0) {
            feed latest = pq.top();
            if (feed_search.find(latest.second.first)!=feed_search.end()) newsfeed.push_back(latest.second.second); // user found
            s.push(latest);
            pq.pop();
        }
        while (!s.empty()){
            pq.push(s.top());
            s.pop();
        }
        return newsfeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (hash_table.find(followerId)==hash_table.end()) hash_table[followerId] = set<int>({followeeId});
        else hash_table[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (hash_table.find(followerId)==hash_table.end()) return ;
        else {
            auto following = hash_table[followerId];
            following.erase(followeeId);
            hash_table[followerId] = following;
        }
    }
};
