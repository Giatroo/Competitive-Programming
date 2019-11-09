#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll H[1123456];

ll binary(ll l, ll r, ll k, ll n){
	ll m, t;
	while(l <= r){
		m = l + floor(r-l)/2;
		t = 0;
		//printf("k = %lld t = %lld l = %lld m = %lld r = %lld\n", k, t, l, m, r);
		for(ll i = 0; i < n; i++){
			t += (m-H[i]);
			//printf("\tH[%lld] = %lld t = %lld\n", i, H[i], t);
			if(t > k) break;
		}
		//printf("k = %lld t = %lld\n", k, t);
		if(t < k) l = m+1;
		else if(t > k) r = m-1;
 		else if(t == k) return m;
	}
	m = l + floor(r-l)/2;
	//printf("l = %lld m = %lld r = %lld\n", l, m, r);
	return m;
}

int main(){
	ll N, M, W;
	ll k, min, max, ret;
	scanf("%lld %lld %lld", &N, &M, &W);
	for(int i = 0; i < N; i++)
		scanf("%lld", H+i);
	sort(H, H+N);
	k = M * W;
	min = H[0];
	max = H[N-1] + k;
	ret = binary(min, max, k, N);	
	
	printf("%lld\n", ret);
		
	return 0;
}
