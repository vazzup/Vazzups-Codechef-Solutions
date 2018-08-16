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
    int n, k, v;
    scanf("%d%d%d", &n, &k, &v);
    int a[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = -1;
        }
    }
    for(int i=0; i<n; i++) {
        printf("1 %d %d\n", i, 0);
        fflush(stdout);
        scanf("%d", &(a[i][0]));
    }
    for(int i=1; i<n; i++) {
        printf("1 %d %d\n", 0, i);
        fflush(stdout);
        scanf("%d", &a[0][i]);
    }
    for(int i=1; i<n; i++) {
        printf("1 %d %d\n", i, n - 1);
        fflush(stdout);
        scanf("%d", &a[i][n - 1]);
    }
    for(int i=1; i<n - 1; i++) {
        printf("1 %d %d\n", n - 1, i);
        fflush(stdout);
        scanf("%d", &a[n - 1][i]);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
