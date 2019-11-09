#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll H[1123456];

ll binary(ll l, ll r, ll k, ll n){
	ll m, t, i;
	while(l <= r){
		m = (l+r)/2;
		t = 0;
		for(i = 0; i < n; i++){
			t += (m-H[i]);
			//printf("\tH[%lld] = %lld t = %lld\n", i, H[i], t);
			if(t > k) break;
		}
		if(t < k) l = m+1;
		else if(t > k) r = m-1;
 		else if(t == k) m;
	}
	m = ((l+r)/2);
	return m;
}

int main(){
	ll N, M, W;
	ll k, p, min, max;
	ll i;
	scanf("%lld %lld %lld", &N, &M, &W);
	for(i = 0; i < N; i++)
		scanf("%lld", H+i);
	k = M * W;
	sort(H, H+N);
	min = H[0];
	max = H[N-1] + k;
	p = binary(min, max, k, N);

	printf("%lld\n", p);

	return 0;
}
