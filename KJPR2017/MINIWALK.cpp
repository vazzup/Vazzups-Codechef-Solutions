#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <unordered_map>

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, q;
		cin >> n >> q;
		vector <ll> a(n);
		for(ll i=0; i<n; i++) {
			cin >> a[i];
		}
		unordered_map <ll, ll> l, r;
		ll steps = 0;
		for(ll i=0; i<n; i++) {
			if(l.find(a[i]) == l.end()) {
				l[a[i]] = steps;
			} else {
				l[a[i]] = min(l[a[i]], steps);
			}
			steps++;
		}
		steps = 0;
		for(ll i=n-1; i>=0; i--) {
			if(r.find(a[i]) == r.end()) {
				r[a[i]] = steps;
			} else {
				r[a[i]] = min(r[a[i]], steps);
			}
			steps++;
		}
		for(ll i=0; i<q; i++) {
			ll k;
			cin >> k;
			if(l[k] < r[k]) cout <<  "misha\n";
			else if(l[k] > r[k]) cout << "nishchith\n";
			else cout << "tie\n";
		}
	}
	return 0;
}
