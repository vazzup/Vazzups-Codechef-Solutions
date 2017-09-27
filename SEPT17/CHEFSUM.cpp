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
			cin >> v[i];
		}
		vector <ll> prefix(n), suffix(n);
		suffix[n - 1] = v[n - 1];
		prefix[0] = v[0];
		for(ll i=1; i<n; i++) {
			prefix[i] = prefix[i - 1] + v[i];
		}
		for(ll i=n-2; i>=0; i--) {
			suffix[i] = suffix[i + 1] + v[i];
		}
		ll mn = 100000000000000LL;
		ll index = -1;
		for(ll i=0; i<n; i++) {
			prefix[i] = prefix[i] + suffix[i];
			if(prefix[i] < mn) {
				mn = prefix[i];
				index = i;
			}
		}
		cout << index + 1 << "\n";
	}
	return 0;
}
