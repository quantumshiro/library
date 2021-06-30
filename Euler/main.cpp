#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include "euler.hpp"

int main(void) {
	for(int i = 0; i < 100; ++i)
		std::cout << euler_phi(i) << std::endl;


	return 0;
}
