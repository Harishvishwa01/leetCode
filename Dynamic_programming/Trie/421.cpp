/*
   author : harish vishwa
   Date   : 26 / 12 / 24
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[2];
    bool containKey(int bit){
        return links[bit] != NULL;
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    private:
    Node* root;
    public:
       Trie(){
          root = new Node();
       }

       void insert(int num){
        Node* temp = root;
        for(int i = 31; i >= 0; i--){
            int bit =  (num >> i) & 1; 
            if(!temp->containKey(bit)){
                temp -> put(bit,new Node());
            }
            temp = temp -> get(bit);
        }
       }

       int getMaxi(int num){
        int maxi = 0;
        Node* temp = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(temp -> containKey(1 - bit)){
                maxi |= (1 << i);
                temp = temp -> get(1 - bit);
            }
            else{
                temp = temp -> get(bit);
            }
        }
        return maxi;
       }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
         Trie o;
         for(int i = 0; i < nums.size(); i++){
            o.insert(nums[i]);
         }
         int maxi = 0;
         for(int i = 0;i < nums.size(); i++){
            int val = o.getMaxi(nums[i]);
            maxi = max(maxi,val);
         }
         return maxi;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();