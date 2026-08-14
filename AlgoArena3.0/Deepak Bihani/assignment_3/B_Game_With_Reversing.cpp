#include <bits/stdc++.h>

#include <cstdint>

using namespace std;

// =======================================================
//                     Type alias
// =======================================================

typedef long long ll;
typedef vector < ll > vi;
typedef vector < pair < int, int >> vii;
typedef vector < vi > vvi;
typedef pair < int, int > pii;


// =======================================================
//                     short hand
// =======================================================

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x)(x).begin(), (x).end()


// =======================================================
//                     constants
// =======================================================

const ll mod1 = 1000000007;
const ll mod2 = 998244353;


// =======================================================
//                     directions
// =======================================================

vi dirx = {
    1,
    -1,
    0,
    0
};

vi diry = {
    0,
    0,
    1,
    -1
};

string dir = {
    'D',
    'U',
    'R',
    'L'
};


// =======================================================
//                     snippets
// =======================================================

// BFS -

// while (!q.empty()) {
//     pii t = q.front();
//     int x = t.ff;
//     int y = t.ss;
//
//     for (int i = 0; i < 4; i++) {
//         int nx = x + dirx[i];
//         int ny = y + diry[i];
//
//         if (nx < n && nx >= 0 && ny < m && ny >= 0) {
//             q.push(mp(nx, ny));
//             break;
//         }
//     }
//
//     if(!q.empty()) q.pop();
// }

// DFS
// int dfs(vector < string > & grid, vvi & vis, int x, int y) {
//     for (int i = 0; i < 4; i++) {
//         int nx = x + dirx[i];
//         int ny = y + diry[i];

//         if (nx < n && nx >= 0 && ny < m && ny >= 0 && grid[nx][ny] != '#' && vis[nx][ny] == 0) {
//             vis[nx][ny] = 1;
//             dfs(grid, vis, nx, ny);
//         }
//     }
//     return 1;
// }

// =======================================================
//                      SOLUTION
// =======================================================




void solve() {
    int n;
    cin >> n;
    string s;
    string t;
    cin >> s >> t;
    int c = 0, rc = 0;
    for(int i=0; i<n; i++) {
        if(s[i] != t[i]) c++;
        if(s[i] != t[n-1 - i]) rc++;
    }
    int ans = min(2*c - c%2, 2*rc + rc%2 - 1);
    if(rc == 0 && c!=0) ans = 2;
    if(c==0) ans = 0;
    cout << ans <<"\n";
    
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

}
