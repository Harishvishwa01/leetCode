#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main() {
    ll n, m;
    cin >> n >> m;
    //cout << gcd(n, m) << endl;

    vector<ll> arr(n);
    vector<ll> arr2(m); 
    for(auto &i : arr) cin >> i;
    for(auto &i : arr2) cin >> i;
    ll g = 0;
    for (int i = 1; i < n; i++) {
        g = gcd(g, arr[i] - arr[0]);
    }

    for(int i = 0; i < m; i++){
        cout<<gcd(arr[0] + arr2[i] , g) <<" ";
    }

    return 0;
}
