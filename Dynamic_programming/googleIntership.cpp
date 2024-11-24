#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> arr(n);
  for(auto &i : arr) cin>>i;
  for(int i = 0; i < n; i++){
      arr.push_back(2 * arr[i]);
  }
  for(auto it : arr) cout<<it<<" ";
  cout<<endl;
 map<int,int> mpp;
 for(auto it : arr) mpp[it]++;
 vector<int> ans;
 for(auto it : mpp){
     if(mpp.count(it.first/2)){
         ans.push_back(it.first/2);
     }
 }
  ans.erase(ans.begin());
  for(auto it : ans) cout<<it <<" ";

    return 0;
}