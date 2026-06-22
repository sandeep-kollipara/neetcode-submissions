class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // brute force - linear search for each person - O(n^2)
        // stack approach
        stack<int> stk;
        // base case - last is 0, penultimate is 1
        vector<int> out(heights.size(), 0);
        if (out.size()>1) out[out.size()-2] = 1;
        // start at the end, result is stack size after popping but before adding current element 
        // add element to stack if top > element else pop until it isn't or empty
        if (out.size()<3) return out;
        stk.push(heights[heights.size()-1]);
        if (heights[heights.size()-1] > heights[heights.size()-2]) stk.push(heights[heights.size()-2]);
        else {
            stk.pop();
            stk.push(heights[heights.size()-2]);
        }
        int pop;
        for (int i=out.size()-3; i>-1; i--) {
            pop=0;
            // add the result to out
            out[i] = stk.size();
            cout << out[i] << ",";
            // stack check
            while (!stk.empty() and heights[i] > stk.top()) {
                stk.pop();
                pop++;
            }
            out[i] = min(out[i], pop+1); // pattern
            cout << pop << endl;
            // add current element
            stk.push(heights[i]);
        }
        return out;
    }
};