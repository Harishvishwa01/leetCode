#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> minHeap;
     for(int i = 0; i < n; i++){
        int num;
         cin>>num;
         minHeap.push(num);
     }

     int k;
     cout<<"k small ele : ";
     cin>>k;
     int num;
    
     
     for(int i = 0; i < k; i++){
         num = minHeap.top();
        minHeap.pop();
     }

     cout<<num;

    return 0;
}
