#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

#define ll long long int
#define pll pair<long long, long long>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define getchar_unlocked getchar
#define F first
#define S second
#define MOD 1000000007

using namespace std;

ll modpow(ll a, ll b, ll mod) {
    ll ans = 1;
    if(mod == 0)
        mod = MOD;
    // cout << "inside the modpow\n";
    a %= mod;
    while(b > 0) {
        if(b & 1) {
            ans *= a;
            ans %= mod;
        }
        b >>= 1;
        a *= a;
        a %= mod;
        // cout << b << " " << a << " " << ans << "\n";
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        // cout << "Input: " << a << " " << b << " " << n << "\n";
        if(a == b) {
            cout << (2 * modpow(a, n, 0)) % MOD << "\n";
        } else {
            // cout << modpow(b, n, a-b) << " " << a-b << "\n";
            cout << __gcd((a - b), (2 * modpow(b, n, a - b)) % (a - b)) % MOD << "\n";
        }
    }
	return 0;
}
