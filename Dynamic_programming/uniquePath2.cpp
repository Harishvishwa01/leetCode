#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size();
        int m = Grid[0].size();

        vector<int> dp(n,0);

        for(int i = 0; i < n; i++){
            vector<int> temp(m,0);
            for(int j = 0; j < m; j++){
                if(Grid[i][j] == 1){
                    temp[j] = 0;
                    continue;
                }
                else{
                if(i == 0 && j == 0 && Grid[i][j] != 1){ temp[j] = 1;continue;}
                    int up = i > 0 ? dp[j] : 0;
                    int left = j > 0 ? temp[j -1] : 0;

                    temp[j] = left + up;
                }
            }
            dp = temp;
        }

        return dp[m -1];
    }
};

int main(){

}