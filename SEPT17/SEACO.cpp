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
	int t;
	cin >> t;
	while(t--) {
		ll n, m;
		cin >> n >> m;
		vector <ll> v(n);
		for(ll i=0; i<n; i++) {
			cin >> v[i];
		}
		vector < pair <ll, pair<ll, ll> > > cm(m);
		for(ll i=0; i<m; i++) {
			cin >> cm[i].F >> cm[i].S.F >> cm[i].S.S;
		}
	}
	return 0;
}
