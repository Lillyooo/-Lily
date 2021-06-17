#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
 
int v[maxn], w[maxn], dp[maxn];
int n, m;
 
int main() {
	while(~scanf("%d %d", &n, &m)){
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < n; i++)
			scanf("%d %d", &v[i], &w[i]);
		for(int i = 0; i < n; i++){
			for(int j = m; j >= 0; j--){
			  if(j >= w[i]){
			  	dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			  }
			} 
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}
