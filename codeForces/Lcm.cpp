#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// Function to compute GCD
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int &x : arr) cin >> x;
    
    // Step 1: Sort in descending order to start with the maximum element
    sort(arr.rbegin(), arr.rend());

    // Step 2: Pick the largest element as the first element
    int g = arr[0];
    int sum = g;
    
    // Step 3: Greedily pick elements to minimize the GCD at each step
    vector<bool> used(n, false);
    used[0] = true; // Mark first element as used

    for (int i = 1; i < n; i++) {
        int best_idx = -1, best_gcd = 0;

        // Find the element that reduces GCD the least
        for (int j = 1; j < n; j++) {
            if (!used[j]) {
                int new_gcd = gcd(g, arr[j]);
                if (new_gcd > best_gcd) {
                    best_gcd = new_gcd;
                    best_idx = j;
                }
            }
        }

        // Update GCD and sum
        g = best_gcd;
        sum += g;
        used[best_idx] = true;
    }

    cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
