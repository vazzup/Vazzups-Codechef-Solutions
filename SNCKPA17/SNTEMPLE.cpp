#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>

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
		vector <ll> h(n);
		vector <ll> cum(n);
		ll sm = 0;
		for(int i=0; i<n; i++) {
			cin >> h[i];
			sm += h[i];
			cum[i] = sm;
		}
		ll m_cost = 1000000000000000000;
		ll m_i = 0, m_j = 0;
		for(int i=0; i<n; i++) {
			if(h[i]) {
				int j = i;
				ll len = 1;
				ll e_v = 2;
				while(j + 1 < n && h[j + 1] >= e_v) {
					j++;
					len++;
					e_v++;
				}
				e_v -= 2;
				while(j + 1 < n && h[j + 1] && e_v) {
					j++;
					len++;
					e_v = min(h[j], e_v);
					e_v--;
				}
				ll cost = 0;
				if(i - 1 > 0)
					cost += cum[i - 1];
				if(j < n)
					cost += cum[n-1] - cum[j];
				ll sum = 0;
				ll half_len = len/2 + 1;
				sum = 2 * ((half_len * (half_len+1))/2);
				sum -= half_len;
				cout << i << " " << j << " " << cost << "\n";
				if(i - 1 > 0) {
					cost += cum[j] - cum [i - 1] - sum;
				}
				if(cost < m_cost) {
					m_cost = cost;
					m_i =  i;
					m_j = j;
				}
				i = j;
			}
		}
		/* ll count = 0;
		for(int i =0; i<m_i; i++) {
			count += h[i];
			h[i] = 0;
		}
		for(int j=m_j+1; j<n; j++) {
			count += h[j];
			h[j] = 0;
		}
		for(int k=0; m_i+k <= m_j-k; k++) {
			count += h[m_i+k] - (k+1);
			h[m_i+k] = k+1;
			if(m_i+k != m_j-k) {
				count += h[m_j-k] - (k+1);
				h[m_j-k] = k+1;
			}
		}
		cout << count << "\n";*/
		cout << m_i << " " << m_j << "\n";
		cout << m_cost << "\n";
	}
	return 0;
}
