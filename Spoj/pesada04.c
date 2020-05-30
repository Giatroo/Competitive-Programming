#include <stdio.h>

const int INF = 0x3f3f3f3f;
int t, n;
int adj[12][12];
int memo[12][5000];
int aux;

int dp(int i, int s) {
	if (s == (1 << n) - 1) return adj[i][0];

	int pdm = memo[i][s];
	if (pdm != -1) return pdm;

	pdm = INF;
	for (int j = 0; j < n; j++) {
		if ((s & (1 << j)) == 0) {
			aux = dp(j, s | (1 << j)) + adj[i][j];
			if (aux < pdm) pdm = aux;
		}
	}

  memo[i][s] = pdm;
  return pdm;
}

int main(int argc, char const *argv[]) {
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
    n++;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < 5000; j++) memo[i][j] = -1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				scanf("%d", &(adj[i][j]));
			}
		}

    /* printf("\n"); */
		/* for (int i = 0; i <= n; i++) { */
			/* for (int j = 0; j <= n; j++) { */
        /* printf("%d ", adj[i][j]); */
      /* } */
      /* printf("\n"); */
    /* } */

		printf("%d\n", dp(0, 1));
	}

	return 0;
}
