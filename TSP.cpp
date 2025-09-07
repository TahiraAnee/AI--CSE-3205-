#include<bits/stdc++.h>
using namespace std;

#define N 4
#define INF INT_MAX

int dist[N][N] = {
    {0, 4, 7, 6},
    {4, 0, 8, 2},
    {7, 8, 0, 5},
    {6, 2, 5, 0}
};

vector<vector<int>> dp(1 << N, vector<int>(N, -1));

int tsp(int mask, int pos) {
    if (mask == (1 << N) - 1) {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int ans = INF;
    for (int city = 0; city < N; city++) {
        if (!(mask & (1 << city))) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    cout << "The minimum cost is " << tsp(1, 0) << endl;
    return 0;
}