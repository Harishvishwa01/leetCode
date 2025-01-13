/*
  Author : "Harish Vishwa"
  Date : "13 / 1 /25" 

*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
 public:
    void dfs(int node,vector<int>& vis,vector<int> adj[],stack<int>& st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
       }
       st.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adjls) {
       int v = adjls.size();
       vector<int> adj[v];
       for(int i = 0; i < v; i++){
           for(auto it : adjls[i]){
               adj[i].push_back(it);
           }
       }
       stack<int> st;
       vector<int> vis(v,0);
       for(int i = 0; i < v; i++){
           if(!vis[i]){
               dfs(i,vis,adj,st);
           }
       }
       vector<int> ans;
       while(!st.empty()){
           int val = st.top();
           ans.push_back(val);
           st.pop();
       }
       return ans;
    }
};