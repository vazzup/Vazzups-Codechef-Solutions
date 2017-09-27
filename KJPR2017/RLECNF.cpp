#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>

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

ll pow_mod(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) {
			ans*=a;
			if(ans > MOD) ans%=MOD;
		}
		a*=a;
		if(a > MOD) a%=MOD;
		b>>=1;
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		map <char, ll> count, char_count;
		ll len = s.size();
		for(ll i=0; i<len; i++) {
			ll num = 0;
			while(s[i]<='9' && s[i]>='0') {
				num = (num*10) + (s[i] - '0');
				i++;
			}
			if(num == 0) num = 1;
			count[s[i]] += num;
		}
		ll ans = 1;
		ll q;
		cin >> q;
		for(ll i=0; i<q; i++) {
			char c = ' ', d = ' ';
			while(c<'a' || c >'z') cin >> c;
			while(d<'a' || d >'z') cin >> d;
			char_count[c]++;
			char_count[d]++;
		}
		/* for(char c = 'a'; c <= 'z'; c++) {
			cout << c << " " << char_count[c] << " " << count[c] << "\n";
		} */
		for(auto it = char_count.begin(); it != char_count.end(); it++) {
			char c = it -> F;
			ll v = it -> S;
			if(count[c] > 0 && v >  0)
			ans *= pow_mod(v + 1, count[c]);
			if(ans > MOD) ans %= MOD;
		}
		ans -= 1;
		cout << ans << "\n";
	}
	return 0;
}
