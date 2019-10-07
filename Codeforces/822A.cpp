#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fat(ll N){
	ll r = 1;
	int i;
	for(i = N; i >= 2; i--)
		r *= i;
	return r;
}

int main()
{
	ll A, B, C;
	cin >> A >> B;
	
	C = min(A, B);
		
	printf("%lld\n", fat(C));

	return 0;
}
