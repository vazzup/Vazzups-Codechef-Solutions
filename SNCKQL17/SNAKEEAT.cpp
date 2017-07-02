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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll t;
	cin >> t;
	while(t--) {
		ll n, q, k;
		cin >> n >> q;
		vector <ll> l;
		for(ll i=0; i<n; i++) {
			cin >> k;
			l.pb(k);
		}
		sort(l.begin(), l.end());
		unordered_map <ll, ll> ct;
		vector <ll> v, rem;
		ll count = 1;
		for(ll i=1; i<n; i++) {
			if(l[i] != l[i-1]) {
				ct[l[i-1]] = count;
				count = 1;
				v.pb(l[i-1]);
			} else {
				count++;
			}
		}
		ct[l[n-1]] = count;
		v.pb(l[n-1]);
		for(ll i=0; i<q; i++) {
			cin >> k;
			vector <ll>::iterator it = lower_bound(v.begin(), v.end(), k);
			ll index = it - v.begin();
			for(ll i=index-1; i>=0; i--) {
				ll remaining 
		}
	}
	return 0;
}
