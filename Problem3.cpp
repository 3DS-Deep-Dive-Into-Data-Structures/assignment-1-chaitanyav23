#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void sparse_t(vector<ll>& v, vector<vector<ll>>& sparse, int n, int logn) {
    for (int i = 0; i < n; i++) {
        sparse[i][0] = v[i];
    }
    
    for (int j = 1; j <= logn; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            sparse[i][j] = sparse[i][j - 1] ^ sparse[i + (1 << (j - 1))][j - 1];
        }
    }
}
ll xor_sum(vector<vector<ll>>& sparse, int l, int r) {
    ll result = 0;
    for (int j = log2(r - l + 1); j >= 0; j--) {
        if ((1 << j) <= r - l + 1) {
            result ^= sparse[l][j];
            l += (1 << j);
        }
    }
    return result;
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int logn = log2(n);

    vector<vector<ll>> sparse(n, vector<ll>(logn + 1));
    sparse_t(v, sparse, n, logn);

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        a-=1;
        b-=1;
        cout << xor_sum(sparse, a, b) << endl;
    }

    return 0;
}

