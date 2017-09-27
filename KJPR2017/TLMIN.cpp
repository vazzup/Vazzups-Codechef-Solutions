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

ll recurse(ll index, vector <ll> &a, vector <ll> &b, vector <ll> &dp, ll n);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll k, n;
		cin >> k >> n;
		vector <ll> a(k);
		vector <ll> b(k);
		vector <ll> dp(k, 100000000000000000LL);
		for(ll i=0; i<k; i++) {
			cin >> a[i];
		}
		for(ll i=0; i<k; i++) {
			cin >> b[i];
		}
		dp[0] = b[0];
		for(int i=1; i<k; i++) {
			ll temp = 0;
			for(int j = i-1; j>=0 && temp < n; j--, temp++) {
				dp[i] = min(dp[i], b[i] + dp[j]);
				if(a[j] > a[i]) break;
			}
		}
		/* for(auto x : dp) {
			cout << x << " ";
		}
		cout << "\n";*/
		cout << dp[k-1] << "\n";
	}
	return 0;
}

ll recurse(ll index, vector <ll> &a, vector <ll> &b, vector <ll> &dp, ll n) {
	ll k = a.size();
	if(dp[index] != -1) return dp[index];
	if(index - n <= 0) return b[index];
	ll temp = 0;
	ll ans = 100000000000000000LL;
	for(int i=index-1; i>=0 && temp < n; i--, temp++) {
		ans = min(ans, recurse(i, a, b, dp, n));
		if(a[i] > a[index]) break;
	}
	return dp[index] = ans + b[index];
}
