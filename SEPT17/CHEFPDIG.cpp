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
		string s;
		cin >> s;
		vector <ll> v(10, 0);
		for(int i=0; i<s.size(); i++) {
			v[s[i] - '0']++;
		}
		for(int i='A'; i<='Z'; i++) {
			int c = i;
			if(v[c%10] > 0) {
				int temp = c%10;
				v[temp]--;
				c /= 10;
				if(v[c%10] > 0) {
					cout << (char)i;
				}
				v[temp]++;
			}
		}
		cout <<  "\n";
	}
	return 0;
}
