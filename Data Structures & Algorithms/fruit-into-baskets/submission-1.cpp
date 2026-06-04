class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int a, b;
        // Define S[] = max number of single fruits from subproblem 0 to i trees
        // Define T[] = max number of 2 fruits from subproblem 0 to i trees
        vector<int> S(fruits.size(), 0), T(fruits.size(), 0);
        // Base case
        a = b = fruits[0];
        S[0] = 1;
        T[0] = 1;
        // Recurrence relation - S[i] = S[i-1]+1 if arr[i]==arr[i-1] else 1
        // T[i] = T[i-1]+1 if arr[i]==arr[i-1] else S[i] + S[i-1] 
        for (int i=1; i<fruits.size(); i++) {
            if (fruits[i]==fruits[i-1]) S[i] = S[i-1]+1;
            else S[i] = 1;
            if (fruits[i]==a or fruits[i]==b) {
                if (fruits[i]==b) {
                    b = a;
                    a = fruits[i];
                } 
                T[i] = T[i-1]+1;
            } else {
                b = a;
                a = fruits[i];
                T[i] = S[i] + S[i-1];
            }
            cout << S[i] << " ";
        }
        cout << endl;
        for (int i=1; i<fruits.size(); i++) {
            cout << T[i] << " ";
        }
        return *max_element(T.begin(), T.end());
    }
};