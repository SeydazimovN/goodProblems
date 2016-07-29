#include <bits/stdc++.h>

using namespace std;

const int mod = int(1e9) + 7;
int binpow(int x, int y) {
	int res = 1;
	while (y > 0) {
		if (y & 1) 
			res = 1LL * res * x % mod;
		y >>= 1;
		x = 1LL * x * x % mod;
	}
	return res;
}

int dp[1050][1050];
int cnt[1050], cntN;

void getDP() {
	for (int k = 1; k <= cntN; ++k) {
		for (int last = 1; last <= cntN; ++last) {
			if (k == 1) dp[k][last] = cnt[last];
			else dp[k][last] = (1LL * dp[k - 1][last - 1] * cnt[last]) % mod;
			dp[k][last] = (1LL * dp[k][last] + dp[k][last - 1]) % mod;
		}
	}
}

bool lucky(int x) {
	while (x > 0) {
		if (x % 10 != 4 && x % 10 != 7)
			return false;
		x /= 10;
	}
	return true;
}

int a[100010], N;
map <int, int> place;
int M;

void getCNT() {
	for (int i = 1; i <= N; ++i) {
		if (lucky(a[i])) {
			if (place[a[i]] == 0) {
				++cntN;
				place[a[i]] = cntN;
			}
			int cur = place[a[i]];
			cnt[cur] += 1;
		}
		else M += 1;
	}
}

int A, B, Mfac;
void getNUM() {
	Mfac = 1;
	for (int i = 1; i <= M; ++i)
		Mfac = 1LL * i % mod;
	A = Mfac;
	B = 1;
}
int get(int len) {
	int res = 1LL * Mfac * binpow(A, mod - 2) % mod * binpow(B, mod - 2) % mod;
	A = 1LL * A * binpow(M - len, mod - 2) % mod;
	B = 1LL * B * (len + 1) % mod;
	return res;
}

int k;

void solve() {
	getCNT();
	getDP();
	int ans = 0;
	getNUM();
	for (int x = k; x >= 0; --x) {
		int rem = k - x;
		int suff = get(rem);
		// cout << suff << " ";
		if (x > cntN) continue;
		int res = dp[x][cntN];
		if (x == 0) res = 1;
		// cout << x << " " << cntN << " " << res << " $ \n";
		res = (1LL * res * suff) % mod;
		if (rem <= M) {
			ans = (1LL * ans + res) % mod;
		}
		// cout << x << " " << res << "\n";
	}
	printf ("%d\n", ans);
}

void input() {
	scanf ("%d %d", &N, &k);
	for (int i = 1; i <= N; ++i)
		scanf ("%d", &a[i]);
}

int main() {
	input();
	solve();	
	return 0;
}
