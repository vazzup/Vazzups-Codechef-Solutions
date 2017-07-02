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
		int n;
		cin >> n;
		vector <int> v;
		for(int i=0; i<2*n; i++) {
			int a;
			cin >> a;
			v.pb(a);
		}
		sort(v.begin(), v.end());
		cout << v[n + n/2] << "\n";
		for(int i=2*n-1, j=0; j < n; i--, j++) {
			cout << v[i] << " " << v[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
