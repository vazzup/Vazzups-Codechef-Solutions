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

int size;
ll a[200005], c[200005], mx[200005];
multiset <ll> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n, k, p;
	string q;
	cin >> n >> k >> p;
	int num_ones = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		a[i+n] = a[i];
		num_ones+=a[i];
	}
	if(k>=n) {
		cin >> q;
		for(int i=0; i<p; i++) {
			if(q[i] == '?') {
				cout << num_ones << "\n";
			}
		}
		return 0;
	}
	size = 2*n;
	int ct = 0;
	for(int i=0; i<k; i++) {
		if(a[i]) ct++;
	}
	c[0] = ct;
	for(int i=1; i<n + k -1; i++) {
		if(a[i-1]) ct--;
		if(a[i+k-1]) ct++;
		c[i] = ct;
	}
	for(int i=n+k-1; i<size; i++) {
		c[i] = c[i-n];
	}
	for(int i=0; i+k-1<n; i++) {
		m.insert(c[i]);
	}
	mx[0] = *m.rbegin();
	for(int i=1; i<n; i++) {
		m.erase(m.find(c[i-1]));
		m.insert(c[i+k-1]);
		mx[i] = *m.rbegin();
	}
	int index=0;
	cin >> q;
	for(int i=0; i<p; i++) {
		if(q[i] == '?') {
			cout << mx[index] << "\n";
		} else {
			index--;
			if(index < 0) {
				index = n-1;
			}
		}
	}
	return 0;
}
