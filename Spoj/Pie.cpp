#include <bits/stdc++.h>

using namespace std;

int R[11234];

bool verifica(double V, int N, int F){
	long long c=0, aux = 0;
	for(int i=N-1 ; i>=0 ; i--){
		c+=floor(M_PI*pow(R[i], 2)/V);
		if(c>F) break;
	}

	return c>=F;
}

double binary(int N, int F){
	double l=0, r=M_PI*pow(R[N-1],2);
	double M = r/2;
	while(r-l >= 1e-5){
		if(verifica(M,N,F)) l=M;	
		else r=M;
		M=(r+l)/2;
	}

	return M;
}

int main(){
	int casos;
	int N, F;

	cin >> casos;
	for(int j = 0; j < casos; j++){
		cin >> N >> F;
		F++;
		for(int i = 0; i < N; i++)
			cin >> R[i];
		sort(R, R+N);
		cout << setprecision(4) << fixed << binary(N,F) << endl;
	}	
	return 0;
}
