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
        int len = s.size();
        vector <bool> h(26, false);
        bool ans = false;
        for(int i=0; i<len; i++) {
            if(h[s[i] - 'a'])
                ans = true;
            else h[s[i] - 'a'] = true;
        }
        if(ans) cout << "yes\n";
        else cout << "no\n";
    }
	return 0;
} 
