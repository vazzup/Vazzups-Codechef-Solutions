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

vector <bool> sieve(1000006, true);
vector <ll> lpf(1000006, -1);

void init() {
	sieve[0] = sieve[1] = false;
	lpf[0] = 1;
	lpf[1] = 1;
	for(ll i=2; i<1000006; i++) {
		lpf[i] = i;
	}
	for(ll i=2; i*i <1000006; i++) {
		if(sieve[i]) {
			for(ll j=i*i; j<1000006; j+=i) {
				sieve[j] = false;
				if(lpf[j] == j)
					lpf[j] = i;
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	init();
	while(t--) {
		ll n, ai;
		vector <ll> v;
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> ai;
			v.pb(ai);
		}
		vector <ll> count(1000006, 0);
		for(int i=0; i<n; i++) {
			ll temp = v[i];
			while(temp) {
				if(temp <= 1 || lpf[temp] == 1) break;
				count[lpf[temp]]++;
				temp/=lpf[temp];
			}
		}
		ll tot_count = 1;
		for(ll i=2; i<1000006; i++) {
			if(count[i]) {
				tot_count *= (count[i] + 1);
				// cout << i << " ";
			}
		}
		// cout << "\n";
		cout << tot_count << "\n";
	}
	return 0;
}
