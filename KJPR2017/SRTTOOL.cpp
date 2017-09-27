#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

#define ll long long int
#define ull unsigned long long int
#define pll pair<long long, long long>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define getchar_unlocked getchar
#define F first
#define S second
#define MOD 1000000007

using namespace std;

vector <ll> max_pow(100005);
vector <ll> lpf(100005);
vector <bool> sieve(100005, true);

ll largest_pow(ll a);
bool cmp(pll a, pll b);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	for(ll i=0; i<100005; i++) {
		max_pow[i] = largest_pow(i);
	}
	for(ll i=0; i<100005; i++) {
		lpf[i] = i;
	}
	sieve[0] = sieve[1] = false;
	for(ll i=2; i*i < 100005; i++) {
		if(sieve[i]) {
			for(ll j = i*i; j<100005; j+=i) {
				if(sieve[j]) {
					sieve[j] = false;
					lpf[j] = i;
				}
			}
		}
	}
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector < pair<ll, ll> > a(n);
		for(ll i=0; i<n; i++) {
			cin >> a[i].F;
			a[i].S = i;
		}
		sort(a.begin(), a.end(), cmp);
		for(ll i=0; i<n; i++) {
			cout << a[i].F << " "; // << lpf[a[i]] << " " << max_pow[a[i]] << "\n";
		}
		cout << "\n";
	}
	return 0;
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	if(max_pow[a.F] == max_pow[b.F]) {
		if (lpf[a.F] == lpf[b.F])
			return a.S < b.S;
		else return lpf[a.F] > lpf[b.F];
	}
	else return max_pow[a.F] > max_pow[b.F];
}

ll largest_pow(ll a) {
	int c = 0;
	for(int i=63; i>=0; i--) {
		if((a>>i)&1LL) {
			return i;
		}
	}
	return 0;
}
