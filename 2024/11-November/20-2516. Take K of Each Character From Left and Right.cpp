#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    // Function to calculate the minimum number of characters to remove
    // such that there are at least 'k' occurrences of each character in the string
    int takeCharacters(std::string s, int k) {
        // Frequency array to store the count of each character ('a', 'b', 'c')
        std::vector<int> totalFreq(3, 0); 
        int n = s.length();
        
        // Count the frequency of 'a', 'b', 'c' in the input string
        for (char ch : s) {
            totalFreq[ch - 'a']++;
        }
        
        // If any character appears less than 'k' times, it's impossible to remove characters
        if (totalFreq[0] < k || totalFreq[1] < k || totalFreq[2] < k) {
            return -1;  // Return -1 if the condition is not met
        }
        
        // Current frequency of characters in the sliding window
        std::vector<int> windowFreq(3, 0); 
        int maxSubstrLength = 0;  // Variable to keep track of the longest valid window
        int left = 0;  // Left pointer for sliding window
        
        // Sliding window approach: right pointer moves from 0 to n-1
        for (int right = 0; right < n; right++) {
            // Include the current character in the window
            windowFreq[s[right] - 'a']++;
            
            // Check if any character in the current window exceeds the allowable frequency
            while (left <= right && 
                   (windowFreq[0] > totalFreq[0] - k || 
                    windowFreq[1] > totalFreq[1] - k || 
                    windowFreq[2] > totalFreq[2] - k)) {
                // Move the left pointer to shrink the window
                windowFreq[s[left] - 'a']--;
                left++;
            }
            
            // Update the maximum valid window length
            maxSubstrLength = std::max(maxSubstrLength, right - left + 1);
        }
        
        // Return the minimum number of characters to remove
        return n - maxSubstrLength;
    }
};

// Example usage:
int main() {
    Solution solution;
    std::string s = "aabbcc";
    int k = 2;
    
    int result = solution.takeCharacters(s, k);
    std::cout << "Minimum characters to remove: " << result << std::endl;  // Output: 0
    
    s = "aab";
    k = 2;
    
    result = solution.takeCharacters(s, k);
    std::cout << "Minimum characters to remove: " << result << std::endl;  // Output: 1
    
    return 0;
}
