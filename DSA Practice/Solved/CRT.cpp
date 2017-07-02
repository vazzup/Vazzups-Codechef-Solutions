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

ll mod_inv(ll a, ll mod);
ll power_mod(ll a, ll b, ll mod);
ll extended_euclid(ll a, ll b, ll &x, ll &y);

int main() {
	/***************************************
	 * Chinese Remainder Theorem
	 * ************************
	 * Program to find number x such that
	 * For all num[i], x % num[i] = rem[i]
	 * Using CRT
	 * ************************
	 * Ref:
	 * https://geeksforgeeks.com/chinese-remainder-theorem-set-2-implementation
	 **************************************/
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	vector <ll> nums, rems, pp, inv;
	ll n, a, prod = 1;
	cin >> n;
	for(ll i=0; i<n; i++) {
		cin >> a;
		prod *= a;
		nums.pb(a);
	}
	for(ll i=0; i<n; i++) {
		cin >> a;
		rems.pb(a);
	}
	pp.resize(n);
	inv.resize(n);
	for(ll i=0; i<n; i++) {
		pp[i] = prod/nums[i];
		inv[i] = mod_inv(pp[i], prod);
	}
	ll ans = 0;
	for(ll i=0; i<n; i++) {
		ll temp = 1;
		temp *= pp[i];
		if(temp > prod) temp %= prod;
		temp *= inv[i];
		if(temp > prod) temp %= prod;
		temp *= rems[i];
		if(temp > prod) temp %= prod;
		ans += temp;
		if(ans > prod) ans %= prod;
		cout << ans << " ";
	}
	cout << "\n";
	for(ll i: nums) {
		cout << i << " ";
	}
	cout << "\n";
	for(ll i: rems) {
		cout << i << " ";
	}
	cout << "\n";
	for(ll i: inv) {
		cout << i << " ";
	}
	cout << "\n";
	for(ll i: pp) {
		cout << i << " ";
	}
	cout << "\n";
	cout << ans << "\n";
	return 0;
}


ll extended_euclid(ll a, ll b, ll &x, ll &y) {
	if(a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	if(a > b) return extended_euclid(b, a, y, x);
	ll x1, y1;
	ll gcd = extended_euclid(b%a, a, x1, y1);
	x = y1 - ((b/a) * x1);
	y = x1;
}

ll mod_inv(ll a, ll mod) {
	// return power_mod(a, mod - 2, mod);
	ll x, y;
	ll g = extended_euclid(a, mod, x, y);
	return x;
}

ll power_mod(ll a, ll b, ll mod) {
	ll ans = 1;
	while(b) {
		if(b & 1) {
			ans *= a;
			if(ans >= mod) {
				ans %= mod;
			}
		}
		a *= a;
		if(a >= mod) {
			a %= mod;
		}
		b >>= 1;
	}
	return ans;
}
