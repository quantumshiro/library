#include <iostream>
#include <vector>

int64_t euler_phi (int64_t n);
std::vector<int> euler_phi_table (int n);

int64_t euler_phi (int64_t n) {
	int64_t ret = n;

	for (int64_t i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			ret -= ret / i;
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) ret -= ret / n;

	return ret;
}

std::vector<int> euler_phi_table (int n) {
	std::vector<int> euler(n + 1);
	for (int i = 0; i <= n; ++i) {
		euler[i] = i;
	}
	for (int i = 2; i <= n; ++i) {
		if (euler[i] == i) {
			for (int j = i; j <= n; j+= i) {
				euler[j] = euler[j] / i * (i - 1);
			}
		}
	}

	return euler;
}
