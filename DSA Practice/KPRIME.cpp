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

vector <bool> sieve(100005, true);
vector <ll> num_facts(100005, 0);
vector < vector <ll> > cum_ans(6, vector <ll> (100005, 0));
void init();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	init();
	while(t--) {
		ll a, b, k;
		cin >> a >> b >> k;
		cout << cum_ans[k][b] - cum_ans[k][a - 1] << "\n";
	}
	return 0;
}

void init() {
	sieve[0] = sieve[1] = false;
	for(ll i=2; i*i <= 100005; ++i) {
		if(sieve[i]) {
			num_facts[i]++;
			for(ll j=i*2; j < 100005; j += i) {
				sieve[j] = false;
				num_facts[j]++;
			}
		}
	}
	for(ll i=1; i <= 5; ++i) {
		for(ll j=2; j<100005; ++j) {
			cum_ans[i][j] = cum_ans[i][j - 1];
			if(num_facts[j] == i) {
				cum_ans[i][j]++;
			}
		}
	}
}
