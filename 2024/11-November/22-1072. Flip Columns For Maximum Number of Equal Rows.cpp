#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> freqMap;

        for (const auto& row : matrix) {
            string pattern;
            if (row[0] == 0) {
                for (int bit : row)
                    pattern += to_string(bit);
            } else {
                for (int bit : row)
                    pattern += to_string(bit ^ 1);
            }
            freqMap[pattern]++;
        }

        int maxFreq = 0;
        for (const auto& pair : freqMap) {
            maxFreq = max(maxFreq, pair.second);
        }

        return maxFreq;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Define the matrix
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    // Call the maxEqualRowsAfterFlips function and output the result
    int result = solution.maxEqualRowsAfterFlips(matrix);
    cout << "Maximum number of equal rows after flips: " << result << endl;

    return 0;
}
