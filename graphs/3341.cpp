#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size();
            int m = moveTime[0].size();
    
            // Min-heap: ((row, col), time)
            priority_queue<
                pair<pair<int, int>, int>,
                vector<pair<pair<int, int>, int>>,
                greater<pair<pair<int, int>, int>>
            > pq;
    
            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
            dist[0][0] = 0;
            pq.push({{0, 0}, 0});
    
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, -1, 1};
    
            while (!pq.empty()) {
                auto [pos, t] = pq.top();
                pq.pop();
                int row = pos.first;
                int col = pos.second;
    
                if (row == n - 1 && col == m - 1) {
                    return t;
                }
    
                for (int i = 0; i < 4; i++) {
                    int nrow = row + dx[i];
                    int ncol = col + dy[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                        int waitTime = max(t + 1, moveTime[nrow][ncol] + 1);
                        if (waitTime < dist[nrow][ncol]) {
                            dist[nrow][ncol] = waitTime;
                            pq.push({{nrow, ncol}, waitTime});
                        }
                    }
                }
            }
            return -1;
        }
    };
    