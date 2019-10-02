#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll H[112345];

ll binary(ll l, ll r, ll k, ll n){
	ll m, t;
	while(l < r-1){
		m = (l+r)/2;
		t = 0;
		for(ll i = 0; i < n; i++){
			t += (m-H[i]);
			if(t > k) break;
		}
		if(t < k) l = m;
		else if(t > k) r = m;
 		else if(t == k) return m;
	}
	m = (l+r)/2;
	return m;
}

int main(){
	ll N, M, W;
	scanf("%d %d %d", &N, &M, &W);
	for(int i = 0; i < N; i++)
		scanf("%d", H+i);
	sort(H, H+N);
	ll k = M * W;
	ll min = H[0];
	ll max = H[N-1] + k;
	ll p = binary(min, max, k, N);	
	
	printf("%d\n", p);
		
	return 0;
}
