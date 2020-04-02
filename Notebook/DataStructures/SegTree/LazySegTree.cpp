#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n - 1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for (auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for (auto it = c.rbegin(); it != c.rend(); it++)
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
#define INF LLONG_MAX
#define M 1000000007

using namespace std;

int const N = 112345; // any upperbound right here
bool const DEBUG = true;

// the original numbers, seqtree and lazy arrays
int arr[N], t[4 * N], lz[4 * N];

// building is the same, but we initial
void build(int l, int r, int i)
{
    if (l == r) 
        t[i] = arr[l];
    else
    {
        int m = (l+r)/2;
        build(l, m, 2*i);
        build(m+1, r, 2*i+1);
        t[i] = t[2*i] + t[2*i+1];
    }
    // the only difference is the initialization of the lz values as 0
    lz[i] = 0;
}

// the update is the method with more changes
void update(int l, int r, int i, int ql, int qr, int x)
{
    // as soon as we get in the node, we check if there are lazy updates
    // that we need to do
    if (lz[i]) {
        // We update the value
        t[i] += lz[i] * (r-l+1);
        if (l != r) { // If we're not in a leaf
            // We propagate the lazy value
            lz[2*i] += lz[i];
            lz[2*i+1] += lz[i];
        }
        // Finally, as we updated the value, we indicate that there's no more lazy updates in this node
        lz[i] = 0;
    }

    // Now we do the update
    if (DEBUG) printf("l = %d r = %d\n", l, r);
    // If the cur segment is outside the query segment, there's nothing to be done
    if (qr < l || r < ql) {
        if (DEBUG) printf("outside\n");
        return;
    }
    if (ql <= l && r <= qr) { // If the cur segment is completily inside the query segment
        // We do the update all in this node and do the lazy propagation
        if (DEBUG) printf("inside\n");
        t[i] += x * (r-l+1);
        lz[2*i] += x;
        lz[2*i+1] += x; 
    } else { // If the cur segment and query segment are partially overlapping
        if (DEBUG) printf("particialy\n");
        int m = (l+r)/2;
        // We update the left and right children
        update(l, m, 2*i, ql, qr, x);
        update(m+1, r, 2*i+1, ql, qr, x);
        // And then update the current node
        t[i] = t[2*i] + t[2*i+1];
    }
}

// In the query, the only difference is that we need to check in the start
// if the current node is up to date
int query(int l, int r, int i, int ql, int qr) {
    if (lz[i]) { // If it's not up to date
        // Then we update it
        t[i] += lz[i] * (r-l+1);
        if (l != r) { // If we're not in a leaf
            // We propagate the lazy value
            lz[2*i] += lz[i];
            lz[2*i+1] += lz[i];
        }
        // Finally, as we updated the value, we indicate that there's no more lazy updates in this node
        lz[i] = 0;
    }
    // You can observate that all the segments of code inside a if (lz[i]) are pretty similar
    // If you want, you can concatenate it into a single auxiliary method

    if (ql <= l && r <= qr) return t[i];
    if (r < ql || qr < l) return 0;

    int m = (l+r)/2;
    return query(l, m, 2*i, ql, qr) + query(m+1, r, 2*i+1, ql, qr);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    int a, b, o, v;
    cout << "Write n and q: " << endl;
    cin >> n >> q;
    cout << "Write n elements for the original array: " << endl;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cout << "Building the segment tree..." << endl;
    build(1, n, 1);
    cout << "Write q operations " << endl;
    for (int i = 0; i < q; i++) {
        cin >> o;
        if (o == 0) { // update
            cin >> a >> b >> v;
            update(1, n, 1, a, b, v);
        }
        else if (o == 1)  { // query
            cin >> a >> b;
            cout << query(1, n , 1, a, b) << endl;
        } else if (o == 2) {
            cin >> a >> b;
            for (; a <= b; a++) printf("lz[%d] = %d\n", a, lz[a]);
        }
        
    }

    return 0;
}
