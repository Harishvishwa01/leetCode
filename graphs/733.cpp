#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int sr, int sc, int color, vector<vector<int>>& image,
             vector<vector<int>>& ans, int delRow[], int delCol[], int st) {
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];
            if (nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and
                image[nRow][nCol] == st and ans[nRow][nCol] != color) {
                dfs(nRow, nCol, color, image, ans, delRow, delCol, st);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int startPixel = ans[sr][sc];
        if(startPixel == color) return ans;
        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};
         dfs(sr, sc, color, image, ans, delRow, delCol, startPixel);
        return ans;
    }
};