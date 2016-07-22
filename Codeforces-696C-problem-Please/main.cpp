#include <bits/stdc++.h>

using namespace std;

const int mod = int(1e9) + 7;
typedef long long llint;
int binpow(llint a, llint b) {
	llint res = 1;
	while (b > 0) {
		if (b % 2) {
			res *= a;
			res %= mod;
		}
		b /= 2;
		a *= a;
		a %= mod;
	}
	return res;
}

bool N_is_even = false;
int k;
llint a[100010];
void input() {
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
		if (a[i] % 2 == 0)
			N_is_even = true;
	}
}

void solve() {
	llint A = 2;
	for (int i = 0; i < k; ++i) 
		A = binpow(A, a[i]);
	A = (A * binpow(2, mod-2)) % mod;
	llint B = A;
	if (N_is_even) 
		A = (A + 1) % mod;
	else {
		A = (A - 1) % mod;
		if (A < 0) A += mod;
	}
	A = (A * binpow(3, mod-2)) % mod;
	printf ("%d/%d \n", int(A), int(B));
}
int main() {	
	input();
	solve();
	return 0;
}
