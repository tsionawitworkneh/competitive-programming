#include <limits> // Required for std::numeric_limits

class Solution {
public:
    int reverse(int x) {
        
        long long reversedNum = 0;

        while (x != 0) {
            int digit = x % 10; // Get the last digit
            x /= 10;            // Remove the last digit

            
            reversedNum = reversedNum * 10 + digit;

            
            
            if (reversedNum > std::numeric_limits<int>::max() || reversedNum < std::numeric_limits<int>::min()) {
                return 0; // If it overflows/underflows, return 0 as per common problem requirements
            }
        }

        
        return static_cast<int>(reversedNum);
    }
};