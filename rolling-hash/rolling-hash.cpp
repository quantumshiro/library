#include <iostream>
#include <vector>
#include <string>

template <unsigned mod>
struct RollingHash {
	std::vector<unsigned> hashed, power;

	inline unsigned mul(unsigned a, unsigned b) const {
		unsigned long long x = (unsigned long long) a * b;
		unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
		asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));

		return m;
	}

	RollingHash (const std::string &s, unsigned base = 10007) {
		int sz = (int) s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);
		power[0] = 1;

		for (int i = 0; i < sz; ++i) {
			power[i + 1] = mul(power[i], base);
			hashed[i + 1] = mul(hashed[i], base) + s[i];
			if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
		}
	}
};
