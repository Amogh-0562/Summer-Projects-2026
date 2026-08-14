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
    int h, w, x, y, a, b;

    cin >> h >> w >> x >> y >> a >> b;

    int delx = a - x;
    int dely = abs(b - y);
    if (delx <= 0) {
        cout << "DRAW\n";
        return;
    }
    if (delx % 2 == 1) {
        int t = (delx+1)/2;
        
        int al = max(1, y-t);
        int ar = min(w, y+t);
        int bl = max(1, b-t+1);
        int br = min(w, b+t-1);
        if (al <= bl && ar >= br) {
            cout << "ALICE\n";
        }
        else cout << "DRAW\n";
        return;
    }
    else {
        int t = (delx)/2;
        int al = max(1, y-t);
        int ar = min(w, y+t);
        int bl = max(1, b-t);
        int br = min(w, b+t);
        if ((al>=bl)&& (ar <= br)) {
            cout << "BOB\n";
        }
        else cout << "DRAW\n";
        return;
    }
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
