#include<bits/stdc++.h> 
#include <vector>  
using namespace std;  

#define ll long long  
#define mod 1000000007  
#define forr(a,b) for(int i = a; i <= b; i++)  

  

int main() {  
#ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin);  
    freopen("output.txt", "w", stdout);  
#endif   

    /*ios::sync_with_stdio(false);  
    cin.tie(nullptr);  
     */

     int n;
     cin>>n;
      int prod = 1;
     forr(1,n) prod *= i;
     cout<<prod;
    return 0;
}