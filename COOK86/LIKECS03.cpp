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
        ll n, k;
        cin >> n  >> k;
        vector <ll> v(n);
        set <ll> s;
        for(ll  i=0; i<n; i++) {
            cin >> v[i];
            s.insert(v[i]);
        }
        ll count = 0;
        for(ll i=0; i<=k-1; i++) {
            if(s.find(1LL<<i) == s.end()) {
                count++;
            }
        }
        cout << count << "\n";
    }
	return 0;
} 
