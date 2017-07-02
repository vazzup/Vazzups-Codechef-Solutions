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
	ll r;
	cin >> r;
	while(r--) {
		ll len;
		string s;
		cin >> len >> s;
		bool snake_start = false, possible = true;
		for(ll i=0; i<len; i++)  {
			if(s[i] == 'H' && !snake_start) {
				snake_start = true;
			} else if(s[i] == 'H') {
				possible = false;
				break;
			} else if(snake_start && s[i] == 'T') {
				snake_start = false;
			} else if(s[i] == 'T') {
				possible = false;
			}
		}
		if(snake_start) possible = false;
		if(!possible) {
			cout << "Invalid\n";
		} else {
			cout << "Valid\n";
		}
	}
	return 0;
}
