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

ll nCr(ll n, ll r, ll p);

vector <bool> sieve(1000006, true);
vector <ll> sieve(1000006);

void init();
void get_prime_powers(ll m, vector <ll> &primes, vector <ll> &powers);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	init();
	int t;
	cin >> t;
	while(t--) {
		ll n, k, m;
		cin >> n >> k >> m;
		get_prime_powers(m, primes, powers);
		for(ll i=0; i < powers.size(); i++) {
			fact_tables[i].resize(powers[i]);
			ll f = 1;
			for(ll j=0; j < powers[i]; j++) {
				fact_tables[i][j] = f;
				if((j+1)%primes[i]!=0) {
					f*=j+1;
				}
				if(f>powers[i]) f%=powers[i];
			}
		}
		
	}
	return 0;
}

void nCr(ll n, ll r, ll p, vector <ll> primes, vector <ll> powers, \
	vector <vector <ll> > &fact_tables) {
	vector < vector <ll>  > result(powers.size());
	for(ll i=0; i<4; i++) {

}

void get_prime_powers(ll m, vector <ll> &primes, vector <ll> &powers) {
	ll a;
	while(m!=1) {
		a = lpf[m];
		primes.pb(a);
		ll b = 1;
		while(m%a == 0 && m!=1) {
			m/=a;
			b*=a;
		}
		powers.pb(b);
	}
}

void init() {
	for(ll i=0; i<1000006; i++) {
		lpf[i] = i;
	}
	sieve[0] = sieve[1] = false;
	for(ll i=2; i*i<1000006; i++) {
		if(sieve[i]) {
			for(ll j=i*i; j<1000006; j+=i) {
				sieve[j] = false;
				lpf[j] = min(i, lpf[j]);
			}
		}
	}
}
