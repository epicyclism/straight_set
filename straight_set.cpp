// straight_set.cpp : Defines the entry point for the application.
//

#include "straight_set.h"
#include <iostream>

template<typename C> void Print(C const& c)
{
	for (auto const& e : c)
		std::cout << e << " ";
	std::cout << "\n";
}

int main()
{
	epicyclism::straight_set<int> ssi{ 0, 1, 2, 3, 4, 5, 6, 7 };
	Print(ssi);
	epicyclism::straight_set<int> ssi2{ 0, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3 };
	Print(ssi2);

	return 0;
}
