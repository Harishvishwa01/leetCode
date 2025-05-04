 #include<bits/stdc++.h>
using namespace std;
//bfs
 bool defect(int src,vector<int>& vis,vector<int> adj[]){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int node,int parent,vector<int>& vis,vector<int> adj[]){
       vis[node] = 1;
       for(auto it : adj[node]){
           if(!vis[it]){
               if(dfs(it,node,vis,adj) == true) return true;
           }
           else if(parent != it){
               return true;
           }
       }
       return false;
   }
    bool isCycle(vector<vector<int>>& adjls) {
        
         int n = adjls.size();
          vector<int> adj[n];
         int m = adjls[0].size();
         vector<int> vis(n,0);
          for (int i = 0; i < n; i++) {
        for (int j : adjls[i]) {
            adj[i].push_back(j);
        }
    }
         for(int i = 0; i < n; i++){
             if(!vis[i]){
                if(defect(i,vis,adj)){
                    return true;
                }
             }
         }
         return false;
    }