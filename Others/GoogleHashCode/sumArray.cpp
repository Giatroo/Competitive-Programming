#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define pb push_back
#define mk make_pair
#define pll pair<ll, ll>
#define cout1(a) cout << (a)
#define cout2(a, b) cout << (a) << " " << (b)
#define cout3(a, b, c) cout << (a) << " " << (b) << " " << (c)
#define cout1e(a) cout1(a) << endl
#define cout2e(a, b) cout2(a, b) << endl
#define cout3e(a, b, c) cout3(a, b, c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define M 1000000007

using namespace std;

int books[112345];
int sums[112345];
int s[112345];
int n_books, ship_time, d;

void reverse() {
  for (int i = 0; i < n_books/2; i++) swap(sums[i], sums[n_books-i-1]);
}

int make_s(int day_i) {
  sort(books, books+n_books, greater<int>());

  // cout << "AFTER SORT\n";
  // fora (i, n_books) cout << books[i] << " ";
  // cout << endl;

  sums[0] = books[0];
  for (int i = 1; i <= n_books-1; i++)
    sums[i] = sums[i-1] + books[i];
  reverse();

  // cout << "SUM:\n";
  // fora (i, n_books) cout << sums[i] << " ";
  // cout << endl;

  int len = n_books / ship_time;
  return sums[max(((day_i+len-1)-d)*ship_time, 0)];
}

int main(int argc, char const *argv[]) {
  cin >> n_books >> ship_time >> d;
  for (int i = 0; i < n_books; i++) cin >> books[i];

  cout << "final\n";
  for (int i = 0; i <= d; i++) {
    cout << (make_s(i)) << " ";
  }
  cout << endl;

  return 0;
}
