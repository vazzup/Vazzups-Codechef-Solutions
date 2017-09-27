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
		ll n, q;
		cin >> n >> q;
		vector <ll> a(n);
		vector < pair< pair <ll, ll>, ll>  > b(n);
		for(ll x=0; x<q; x++) {
			ll i, j, val;
			cin >> i >> j >> val;
			a[--i] += val;
			a[--j] += val;
		}

	}
	return 0;
}
