class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size()-1;
        while (high-low>1) {
            if (numbers[high] + numbers[low] < target) low++;
            else if (numbers[high] + numbers[low] > target) high--;
            else return vector<int>({low+1, high+1});
        }
        return vector<int>({low+1, high+1});
    }
};
