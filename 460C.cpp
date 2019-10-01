#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll W[112345];

ll binary(ll l, ll r, ll k, ll n){
	ll m, t;
	while(l < r - 1){
		m = (l+r)/2;
		for(ll i = 0, t = 0; i < n; i++)
			t += (m-W[i]);
		if(t < m) l = m;
		else if(t > m) r = m;
 		else if(t == m) return t;
	}
	return t;
}

int main(){
	ll N, M, W;
	scanf("%d %d %d", &N, &M, &W);
	for(int i = 0; i < N; i++)
		scanf("%d", W+i);
	sort(W, W+N);
	ll k = M * W;
	ll min = W[0];
	ll max = W[N-1] + k;
	ll p = binary(min, max, k, N);	
	
	printf("%d\n", p);
		
	return 0;
}
