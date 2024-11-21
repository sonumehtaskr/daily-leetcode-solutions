#include <iostream>
#include <vector>
#include <cstring> // For memset
using namespace std;

class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        // Initialize grid with zeros
        int g[m][n];
        memset(g, 0, sizeof(g));

        // Mark guards and walls as 2
        for (auto &e : guards)
        {
            g[e[0]][e[1]] = 2;
        }
        for (auto &e : walls)
        {
            g[e[0]][e[1]] = 2;
        }

        // Directions: up, right, down, left
        int dirs[5] = {-1, 0, 1, 0, -1};

        // Process each guard's line of sight
        for (auto &e : guards)
        {
            for (int k = 0; k < 4; ++k)
            {
                int x = e[0], y = e[1];
                int dx = dirs[k], dy = dirs[k + 1];

                // Check cells in current direction until hitting boundary or obstacle
                while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && g[x + dx][y + dy] < 2)
                {
                    x += dx;
                    y += dy;
                    g[x][y] = 1;
                }
            }
        }

        // Count unguarded cells (cells with value 0)
        int unguardedCount = 0;
        for (int i = 0; i < m; i++)
        {
            unguardedCount += count(g[i], g[i] + n, 0);
        }

        return unguardedCount;
    }
};

// Example usage
int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Define the example case with m, n, guards, and walls
    int m = 4, n = 6;
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};

    // Call the countUnguarded function and output the result
    int result = solution.countUnguarded(m, n, guards, walls);
    cout << "Number of unguarded cells: " << result << endl;

    return 0;
}