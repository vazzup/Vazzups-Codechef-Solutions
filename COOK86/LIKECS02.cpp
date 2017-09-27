#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <deque>
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
         ll n;
         cin >> n;
         deque <ll> q;
         for(int i=0; i<=n/2; i++) {
             q.push_back(n+i);
             if(i != 0)
                q.push_front(n-i);
         }
         ll sz = q.size();
         if(sz > n) {
             q.pop_back();
         }
         for(ll x : q) {
             cout << x << " ";
         }
         cout << "\n";
    }
	return 0;
} 
