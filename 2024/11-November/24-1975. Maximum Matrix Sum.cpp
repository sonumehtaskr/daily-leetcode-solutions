#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib> // for abs

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minValue = INT_MAX;
        long long sum = 0;
        int negCount = 0;

        // Traverse the matrix to calculate the sum and track negative values
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] < 0)
                    negCount++;  // Count the negative numbers
                int absValue = abs(matrix[i][j]);  // Get absolute value
                minValue = min(minValue, absValue);  // Track the smallest absolute value
                sum += absValue;  // Add absolute value to sum
            }
        }

        // If the number of negative elements is even, return the sum
        if (negCount % 2 == 0)
            return sum;
        return sum - 2 * minValue;  // If odd, adjust the sum by removing the smallest element twice
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> matrix1 = {
        {1, -2, 3},
        {-4, 5, -6},
        {7, 8, -9}
    };

    cout << "Max Matrix Sum (Example 1): " << sol.maxMatrixSum(matrix1) << endl;

    // Example 2
    vector<vector<int>> matrix2 = {
        {1, 2},
        {3, 4}
    };

    cout << "Max Matrix Sum (Example 2): " << sol.maxMatrixSum(matrix2) << endl;

    // Example 3
    vector<vector<int>> matrix3 = {
        {-1, -2, -3},
        {-4, -5, -6}
    };

    cout << "Max Matrix Sum (Example 3): " << sol.maxMatrixSum(matrix3) << endl;

    return 0;
}
