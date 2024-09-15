#include <bits/stdc++.h>
using namespace std; 
 vector<int> heap;
void heapify(int ind){

    while(ind > 0){
    int parent = (ind - 1) >> 1;

    if(heap[ind] > heap[parent]){
        swap(heap[ind],heap[parent]);
        ind = parent;
    }
    else{
        break;
    }
    }
}
int parent(int i ){return (i - 1) >> 1;}
int left(int i){return 2 * i + 1;}
int right(int i){return 2 * i + 2;}


void heapDown(int ind){
    int size = heap.size();
    int l= left(ind);
    int r = right(ind);
    int lar = ind;

    if(l < heap.size() && heap[lar] < heap[l]) lar = l;
    if(r < heap.size() && heap[lar] < heap[r]) lar = r;

    if(lar != ind){
        swap(heap[ind],heap[lar]);
        heapDown(lar);
    }

    
}

void push(int x){
    heap.push_back(x);
    heapify(heap.size() - 1);
}

int pop(){
    if(heap.size() == 0){
        return -1;
    }
    int maxi = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapDown(0);
    return maxi;
}
int main(){
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        push(val);
    }

    for (auto it : heap) {
        cout << it<< " ";
    }
    cout << endl;

   int num;
   cout<<"enter k : ";
   cin>>num;
   int x ;
   for(int i = 0; i < num; i++){
    x =  pop();
   }
   cout<<x;
}