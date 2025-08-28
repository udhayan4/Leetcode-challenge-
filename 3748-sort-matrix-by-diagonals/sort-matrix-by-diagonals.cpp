#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return grid;

        // Process bottom-left diagonals (i >= j)
        for (int d = 0; d < n; ++d) {
            vector<int> elements;
            vector<pair<int, int>> positions;

            for (int j = 0; j <= n - 1 - d; ++j) {
                int i = j + d;
                elements.push_back(grid[i][j]);
                positions.emplace_back(i, j);
            }

            sort(elements.rbegin(), elements.rend());

            for (int k = 0; k < elements.size(); ++k) {
                int i = positions[k].first;
                int j = positions[k].second;
                grid[i][j] = elements[k];
            }
        }

        // Process top-right diagonals (i < j)
        for (int d = 1; d < n; ++d) {
            vector<int> elements;
            vector<pair<int, int>> positions;

            for (int i = 0; i < n - d; ++i) {
                int j = i + d;
                elements.push_back(grid[i][j]);
                positions.emplace_back(i, j);
            }

            sort(elements.begin(), elements.end());

            for (int k = 0; k < elements.size(); ++k) {
                int i = positions[k].first;
                int j = positions[k].second;
                grid[i][j] = elements[k];
            }
        }

        return grid;
    }
};