class Solution {
public:
    int jump(vector<int>& nums) {
        int depth=0;
        queue<int> q1;
        q1.push(nums.size()-1);
        while (q1.front()!=0) {
            queue<int> q2;
            int idx = q1.front();
            q1.pop();
            for (int i=idx-1; i>-1; i--) {
                if (nums[i]+i>=idx) q2.push(i);
            }
            if (q1.empty()) {
                q1 = q2;
                queue<int> empty;
                swap(q2,empty);
                depth++;
            }
        }
        return depth;
    }
};
