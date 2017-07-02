#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

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
	struct tnode* c[2];
} tnode;

unordered_map <ll, tnode*> get_trie;
unordered_map <ll, ll> get_key;
unordered_map <ll, vector <ll> > adj;
bool special = false;

void dfs(ll id);
tnode* add_num(tnode* parent, ll key);
ll get_min(tnode* root, ll k);
ll get_max(tnode* root, ll k);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n, q, r, key;
	cin >> n >> q >> r >> key;
	get_trie[r] = add_num(NULL, key);
	get_key[r] = key;
	for(ll i=0; i<n-1; i++) {
		ll u, v, k;
		cin >> u >> v >> k;
		adj[v].pb(u);
		get_key[u] = k;
	}
	dfs(r);
	ll last_answer = 0;
	for(ll i=0; i<q; i++) {
		ll t, u, v, k;
		cin >> t;
		t ^= last_answer;
		if(t == 0) {
			cin >> v >> u >> k;
			v ^= last_answer;
			u ^= last_answer;
			k ^= last_answer;
			adj[v].pb(u);
			get_key[u] = k;
			get_trie[u] = add_num(get_trie[v], k);
		} else {
			cin >> v >> k;
			v ^= last_answer;
			k ^= last_answer;
			if(v == 6) special = true;
			ll mn = get_min(get_trie[v], k);
			ll mx = get_max(get_trie[v], k);
			special = false;
			cout <<  (mn^k) << " " << (mx^k) << "\n";
			last_answer = mn^mx;
		}
	}
	return 0;
}

tnode* add_num(tnode* parent, ll key) {
	bool already_present = true;
	tnode* ptr = parent;
	for(int i=31; i>=0; i--) {
		if(ptr == NULL) {
			already_present = false;
			break;
		}
		int index = ((key&(1LL<<i)) > 0)? 1:0;
		ptr = ptr->c[index];
	}
	if(ptr == NULL) already_present = false;
	if(already_present) return parent;
	tnode* parent2 = new tnode;
	tnode* ptr2 = parent2;
	ptr = parent;
	bool ptr_sync = true;
	if(ptr == NULL) ptr_sync = false;
	for(int i=31; i>=0; i--) {
		int index = ((key&(1LL<<i)) > 0)? 1:0;
		ptr2->c[index] = new tnode;
		if(ptr_sync)
		ptr2->c[1 - index] = ptr->c[1-index];
		else ptr2->c[1 - index] = NULL;
		if(ptr_sync && ptr->c[index] != NULL) {
			ptr = ptr->c[index];
		} else  {
			ptr_sync = false;
		}
		ptr2 = ptr2->c[index];
	}
	return parent2;
}

void dfs(ll id) {
	for(int i=0; i<((int)adj[id].size()); i++) {
		get_trie[adj[id][i]] = add_num(get_trie[id], get_key[adj[id][i]]);
		dfs(adj[id][i]);
	}
}

ll get_max(tnode* root, ll key) {
	ll ans = 0;
	for(int i=31; i>=0; i--) {
		int index = ((key&(1LL<<i)) > 0)? 0:1;
		if(root->c[index] == NULL) {
			index = 1 - index;
		} else {
			ans |= (index<<i);
			root = root->c[index];
			continue;
		}
		if(root->c[index] == NULL) {
			return ans;
		} else {
			ans |= (index<<i);
			root = root->c[index];
		}
	}
	return ans;
}

ll get_min(tnode* root, ll key) {
	ll ans = 0;
	for(int i=31; i>=0; i--) {
		int index = ((key&(1LL<<i)) > 0)? 1:0;
		if(root->c[index] == NULL) {
			index = 1 - index;
		} else {
			ans |= (index<<i);
			root = root->c[index];
			continue;
		}
		if(root->c[index] == NULL) {
			return ans;
		} else {
			ans |= (index<<i);
			root = root->c[index];
		}
	}
	return ans;
}
