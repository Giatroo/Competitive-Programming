#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll S[112345];

ll binary(ll x, ll l, ll r){
	ll m;
	while(l < r-1){
		m = (l+r)/2;
		if(S[m] == x)
			return m;
		if(S[m] < x)
			l = m;
		else
			r = m;
	}
	return -1;
}

int main(){
    ll n, k;
	ll r;
    scanf("%lld %lld", &n, &k);
	int count = n;
    for(int i = 0; i < n; i++)
        scanf("%lld", &(S[i]));
    sort(S, S+n);

	for(int i = 0; i < n; i++){
		if(S[i] != 0){	
			r = binary(k*S[i], i, min(n, k*S[i]));
			if(r != -1){
				S[r] = 0;	
				count--;
			}
		}
	}
	printf("%d\n", count);	    
	return 0;
}
