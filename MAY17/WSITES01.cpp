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

typedef struct node {
	vector  <struct node*> c;
	bool prefix_end;
} node;

node *root1, *root2;
bool not_possible = false;

node* get_node();
void add_word(node* root, string s);
void check_word(node* root, string s);
void get_solution(node* root, set <string> &s, string current_string);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	root1 = get_node();
	// root2 = get_node();
	int n;
	cin >> n;
	string a, b;
	vector <pair<string, string> > v;
	for(int i=0; i<n; i++) {
		cin >> a >> b;
		v.pb(mp(a, b));
	}
	for(int i=0; i<n; i++) {
		if(v[i].F == "+") {
			add_word(root1, v[i].S);
		}
	}
	for(int i=0; i<n; i++) {
		if(v[i].F == "-") {
			check_word(root1, v[i].S);
		}
	}
	if(not_possible) {
		cout << "-1\n";
		return 0;
	}
	set <string> s;
	get_solution(root1, s, "");
	cout << s.size() << "\n";
	for(set<string>::iterator it = s.begin(); it!=s.end(); it++) {
		cout << *it << "\n";
	}
	
	return 0;
}

node* get_node() {
	node* temp = new node;
	temp->c.resize(26);
	for(int i=0; i<26; i++) {
		temp->c[i] = NULL;
	}
	temp->prefix_end = false;
	return temp;
}

void add_word(node* root, string s) {
	int len = s.size();
	for(int i=0; i<len; i++) {
		if(root->c[s[i] - 'a'] == NULL) {
			root->c[s[i] - 'a'] = get_node();
			root = root->c[s[i] - 'a'];
		} else {
			root = root->c[s[i] -'a'];
		}
	}
}

void check_word(node* root, string s) {
	int len = s.size();
	for(int i=0; i<len;i ++) {
		if(root->c[s[i] - 'a'] == NULL) {
			root->c[s[i] - 'a'] = get_node();
			root = root->c[s[i] - 'a'];
			root->prefix_end = true;
			return;
		} else {
			root = root->c[s[i] - 'a'];
			if(root->prefix_end) {
				return;
			}
		}
	}
	not_possible = true;
	return;
}

void get_solution(node* root, set <string> &s, string current_string) {
	if(root == NULL) return;
	for(int i=0; i<26; i++) {
		get_solution(root->c[i], s, current_string + (char)('a' + i));
	}
	if(root->prefix_end) {
		s.insert(current_string);
	}
}

