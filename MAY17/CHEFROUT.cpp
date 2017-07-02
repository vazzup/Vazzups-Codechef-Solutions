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
	int t, n;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		n = s.size();
		bool no_c = false, no_e = false, possible = true;
		for(int i=0; i<n; i++) {
			switch(s[i]) {
				case 'C': {
					if(no_c) {
						possible = false;
					}
					break;
				} case 'E': {
					if(no_e) {
						possible = false;
					}
					no_c = true;
					break;
				} case 'S': {
					no_e = true;
					no_c = true;
					break;
				}
			}
			if(!possible) break;
		}
		if(!possible) cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}
