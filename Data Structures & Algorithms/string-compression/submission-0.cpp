class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, j=0, counter=1; // writer, seeker and counter
        do{
            cout << counter << endl;
            j++;        
            if (j<chars.size() and chars[j]!=chars[j-1]) { //write the j-1 char
                chars[i] = chars[j-1];
                i++;
                if (counter > 1) {
                    for (char c : to_string(counter)) {
                        chars[i] = c;
                        i++;
                    }
                }
                counter=1; // for j
            } else if (j< chars.size() and chars[j]==chars[j-1]) {
                counter++; /// for j
            } else { // write the last char
                chars[i] = chars[j-1];
                i++;
                if (counter > 1) {
                    for (char c : to_string(counter)) {
                        chars[i] = c;
                        i++;
                    }
                }
            }
        } while(j<chars.size());
        return i;
    }
};