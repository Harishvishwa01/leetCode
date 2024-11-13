/*
Author Harish Vishwa 
created 13 / 11 / 24 
*/ 
 #include<bits/stdc++.h>
 using namespace std;
 class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int fbuy = INT_MAX,sbuy = INT_MAX,sSell = 0,fsell = 0;

     for(auto it : prices){
        fbuy = min(fbuy,it);
        fsell = max(fsell,it - fbuy);
        sbuy = min(sbuy,it - fsell);
        sSell = max(sSell,it - sbuy);
     }
       return sSell;
    }
}; 

auto init = [](){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 0;
}();