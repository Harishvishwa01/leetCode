#include <bits/stdc++.h>
using namespace std;  
#define ll long long 
int main() {  
    int t;  
    cin >> t; // Read number of test cases  
   while(t--){
       int n;
       cin>>n;
       vector<ll> arr(n);
       for(int i = 0; i < n; i++) cin>>arr[i];
       int flag = 0;
       int indr;
       int indl;
       int neg = 0;



      for(int i = 0; i < n; i++){
         if(arr[i] < 0){
             flag = 1;
             indl = i;
             break;
         }
      }

      if(flag == 0){
         cout<<0<<endl;
         break;
      } 
       flag = 0;
      
     for(int i = n -1; i >= 0; i--){
         if(arr[i] > 0){
             flag = 1;
             indr = i;
             break;
         }
         else{
             flag = 0;
         }
     }

      if(flag == 0){
         cout<<0<<endl;
         break;
      } 
     else{
         for(int i = indl; i<=indr; i++){
             if(arr[i] < 0) neg++;
         }
         cout<<neg<<endl;
     }
   
}
}