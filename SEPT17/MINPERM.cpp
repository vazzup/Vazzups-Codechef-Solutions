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
		ll n;
		cin >> n;
		vector <ll> v(n);
		for(ll i=0; i<n; i++) {
			v[i] = i+1;
		}
		for(ll i=0; i+1<n; i+=2) {
			v[i] += v[i+1];
			v[i+1] = v[i] - v[i+1];
			v[i] -= v[i+1];
		}
		if(n % 2 == 1) {
			v[n - 2] += v[n - 1];
			v[n - 1] = v[n - 2] - v[n - 1];
			v[n - 2] -= v[n - 1];
		}
		for(auto x: v) {
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}
