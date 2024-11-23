#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to rotate the box 90 degrees clockwise
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // Get the number of rows and columns in the box
        int row = box.size(), col = box[0].size();

        // Initialize a new 2D vector to store the rotated box
        // The rotated box will have the number of rows equal to the number of columns of the original box
        // and the number of columns equal to the number of rows of the original box.
        vector<vector<char>> rotate(col, vector<char>(row, '.'));

        // Iterate through each row of the original box
        for (int i = 0; i < row; i++) {
            // Track the position of the bottom-most empty space in the new rotated box
            int bottom = col - 1;

            // Traverse the current row from right to left (reverse order)
            for (int j = col - 1; j >= 0; j--) {
                // If we encounter a rock ('#'), we move it to the bottom-most position in the rotated box
                if (box[i][j] == '#') {
                    rotate[bottom][row - 1 - i] = '#';  // Place rock in rotated position
                    bottom--;  // Move the bottom marker up (next empty space)
                }
                // If we encounter an obstacle ('*'), we place it directly in the rotated box and
                // reset the bottom marker to the position just above the obstacle
                else if (box[i][j] == '*') {
                    rotate[j][row - 1 - i] = '*';  // Place obstacle in rotated position
                    bottom = j - 1;  // Reset bottom marker to above the obstacle
                }
            }
        }
        
        // Return the rotated box
        return rotate;
    }
};

int main() {
    Solution solution;

    // Example 1: Rotating a box with rocks and obstacles
    vector<vector<char>> box = {
        {'#', '.', '#', '*'},
        {'#', '*', '#', '.'},
        {'#', '#', '.', '.'}
    };

    vector<vector<char>> rotatedBox = solution.rotateTheBox(box);

    // Print the rotated box
    std::cout << "Rotated Box:" << std::endl;
    for (const auto& row : rotatedBox) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
