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

typedef struct tnode {
	tnode *left, *right;
	ll val;
} tnode;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector < pll > adj1(n);
		vector < pll > adj2(n);
		vector < tnode* > tree_root(n);
		for(ll i=1; i<n; i++) {
			ll a, b;
			cin >> a >> b;
			--a; --b;
			adj1[a].pb(b);
			adj1[b].pb(a);
		}
		for(ll i=1; i<n; i++) {
			ll a, b;
			cin >> a >> b;
			--a; --b;
			adj2[a].pb(b);
			adj2[b].pb(a);
		}
		
	}
	return 0;
}

tnode* insert(tnode *root, ll k) {
	if(root == NULL) {
		root = new tnode;
		root -> left = root -> right = NULL;
		root -> val = k;
	} else if(k >= root -> val) {
		tnode *
		root -> right = insert(root -> right, k);
	} else {
		root -> left = insert(root -> left, k);
	}
	return root;
}

bool search(tnode *root, ll k) {
	if(root == NULL) return false;
	if(root -> val == k) {
		return true;
	} else if(root -> val >= k) {
		return search(root -> right, k);
	} else {
		return search(root -> left, k);
	}
}

void dfs(ll node, ll parent, vector <ll> adj[], set <ll> ancestors) {

