#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find the maximum sum of a subarray of length k
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();  // Get the size of the input array
        unordered_set<int> elements;  // Set to track unique elements in the window
        long long current_sum = 0;  // Current sum of the window
        long long max_sum = 0;  // Variable to track the maximum sum found
        int begin = 0;  // Pointer for the start of the sliding window
        
        // Iterate through the array with the `end` pointer
        for (int end = 0; end < n; end++) {
            // If the current element is unique in the window
            if (elements.find(nums[end]) == elements.end()) {
                current_sum += nums[end];  // Add current element to the sum
                elements.insert(nums[end]);  // Insert current element into the set
                
                // If the window size reaches k, calculate the sum
                if (end - begin + 1 == k) {
                    max_sum = max(max_sum, current_sum);  // Update the max sum if needed
                    current_sum -= nums[begin];  // Remove the element at the start of the window
                    elements.erase(nums[begin]);  // Remove the element from the set
                    begin++;  // Move the start pointer forward to shrink the window
                }
            } else {
                // If the current element is a duplicate, shrink the window from the start
                while (nums[begin] != nums[end]) {
                    current_sum -= nums[begin];  // Remove the element from the sum
                    elements.erase(nums[begin]);  // Remove the element from the set
                    begin++;  // Move the start pointer forward to remove duplicates
                }
                begin++;  // Skip the duplicate element at `begin`
            }
        }
        
        return max_sum;  // Return the maximum sum found
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};  // Example input array
    int k = 3;  // Length of the subarray
    
    long long result = solution.maximumSubarraySum(nums, k);  // Call the function
    cout << "Maximum subarray sum of length " << k << " is: " << result << endl;
    
    return 0;
}
