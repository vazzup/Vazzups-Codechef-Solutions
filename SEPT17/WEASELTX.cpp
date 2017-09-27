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

vector < vector <ll> > adj;
vector <ll> x;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n, q;
	cin >> n >> q;
	adj.resize(n);
	x.resize(n);
	for(ll i=0; i<n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;b--;
		adj[a].pb(b);
	}
	for(ll i=0; i<n; i++) {
		cin >> x[i];
	}

	return 0;
}
