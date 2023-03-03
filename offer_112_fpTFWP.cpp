#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int, pii> piii;

class Solution {
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> marks(m, vector<int>(n, 1));
        vector<piii> v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back(piii(matrix[i][j], pii(i, j)));
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            int x = v[i].second.first;
            int y = v[i].second.second;
            if (marks[x][y] == 1) dfs(x, y, marks, matrix, dir);
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, marks[i][j]);
            }
        }
        return ans;
    }

    void dfs(int x, int y, vector<vector<int>>& marks, vector<vector<int>>& matrix, vector<vector<int>>& dir) {
        
        int m = marks.size(), n = marks[0].size();
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && marks[nx][ny] < marks[x][y] + 1 && matrix[nx][ny] > matrix[x][y]) {
                marks[nx][ny] = marks[x][y] + 1;
                dfs(nx, ny, marks, matrix, dir);
            }
        }
    }
};