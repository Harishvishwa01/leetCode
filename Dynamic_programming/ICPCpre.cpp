#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> memo;
vector<int> res;
bool findSubset(int i, int val, int k, const vector<int>& arr, vector<int>& ind) {
    if (val == k && !ind.empty()) {
        res = ind; 
        return true;
    }
    if (i < 0) return false;
    pair<int, int> p = make_pair(i,  val);
    if (memo.count(p)) return memo[p];
    bool not_take = findSubset(i - 1, val, k, arr, ind);
    ind.push_back(i + 1); 
    bool take = findSubset(i - 1, val & arr[i], k, arr, ind);
    ind.pop_back(); 
    return memo[p] = not_take || take;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        memo.clear(); 
        res.clear();
        vector<int> ind; 
        bool found = findSubset(n - 1, (1 << 30) - 1, k, arr, ind);

        if (found) {
            cout << "YES" << endl;
            cout << res.size() << endl;
            for (int idx : res) {
                cout << idx << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}