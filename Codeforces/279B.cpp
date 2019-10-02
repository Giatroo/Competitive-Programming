#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll a[112345];

int binary(int i, int n, int t){
	int r = n;
	int l = i;
	int meio = (r+l+1)/2;

	//cout << "\tEntrou em binary!! ";
	//printf("i = %d\n", i);

	//printf("l = %d meio = %d r = %d\n", l, meio, r);

	while(r > l+1){
		if(a[meio] - a[i-1] <= t){
				l = meio;
				meio = (r+meio)/2;
		//		printf("Right\t");
		} else {
			r = meio-1;			
			meio = (l+meio)/2;
		//	printf("Left\t");
		}
		//printf("l = %d meio = %d r = %d\n", l, meio, r);
	}
	
	if(a[r] - a[i-1] <= t){
	//	printf("Retornando %d\n\n", r - i + 1);
		return r - i + 1;
	}
	if(a[l] - a[i-1] <= t)
	return l - i + 1;

	return 0;
}

int main(){
	ll n, t;
	int aux, temp;
	int i;

	cin >> n >> t;

	a[0] = 0;
	cin >> a[1];
	for(i = 2; i <= n; i++){
		cin >> aux;
		a[i] = a[i-1] + aux;
	}		
	
	aux = -1;
	for(i = 1; i <= n; i++){
			temp = binary(i, n, t);
			if(temp > aux) aux = temp;
	}

	cout << aux << endl;

	return 0;
}
