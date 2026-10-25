class Solution {
public:
    int maxVowels(string s, int k) {
        auto is_vowel=[](char a){
            if (a=='a' 
            or a=='e' 
            or a=='i' 
            or a=='o' 
            or a=='u') return true;
            return false;
        };
        int i=0, j=0, vowels=0, maximum=0;
        while (j<s.length()) {
            // create sliding window
            while (j<k) {
                if (is_vowel(s[j])) vowels++;
                j++;
            }
            // check max
            maximum = max(vowels, maximum);
            // shift by one
            if (is_vowel(s[i])) vowels--;
            i++;
            if (is_vowel(s[j])) vowels++;
            j++;
        }
        maximum = max(vowels, maximum);
        return maximum;
    }
};
