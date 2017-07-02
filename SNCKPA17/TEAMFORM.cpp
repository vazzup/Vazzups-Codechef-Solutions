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
	int n, m, t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i=0; i<m; i++) {
			int a, b;
			cin >> a >> b;
		}
		cout << ((n%2 == 0)?"yes":"no") << "\n";
	}
	return 0;
}
