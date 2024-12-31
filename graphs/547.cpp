#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<int> adj[],vector<int>& vis,int start){
    vis[start] = 1;
    for(auto it : adj[start]){
        if(!vis[it]){
            dfs(adj,vis,it);
        }
    }
}
    void bfs(vector<int> adj[],vector<int>& vis,int start){
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> adj[v];
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(v,0);
        int cnt = 0;
        for(int i = 0; i < v; i++){
           if(!vis[i]){
            bfs(adj,vis,i);
            cnt++;
           }
        }
        return cnt;
    }
};

int main(){

}