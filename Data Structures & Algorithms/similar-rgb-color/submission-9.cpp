class Solution {
public:
    string similarRGB(string color) {
        auto nearest = [](string hex) -> string {
            int val = stoi(hex, nullptr, 16);  // Convert hex to decimal
            int closestDigit = round(val / 17.0);  // Nearest multiple of 17
            closestDigit = min(15, max(0, closestDigit));  // Clamp to 0-15
            char digit = "0123456789abcdef"[closestDigit];
            return string(2, digit);
        };
        
        return "#" + nearest(color.substr(1, 2)) + 
               nearest(color.substr(3, 2)) + 
               nearest(color.substr(5, 2));
    }
};