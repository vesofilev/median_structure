/**
 * \file test.cpp
 * \author Veselin Filev
 *
 * Test of online median finding
 */


#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "median_struct.hpp"
#include <vector>


double bruteForceMedian(std::vector<double> vec) {
	std::sort(vec.begin(), vec.end());
	if (vec.size() % 2 == 1.0)
		return vec[vec.size() / 2];
	else 
		return 0.5 * (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]);
}


TEST_CASE( "Median is correctly computed", "[median]" ) {
	std::vector<double> elements{17.5, 3.5, 5.0, 3.5, 13.0, 
								 6.0, 13.5, 3.0, 2.5, 9.5,
								 7.5, 8.0, 4.0, 20.0, 3.0,
								 12.5, 10.5, 7.0, 17.5, 18.0};
	std::vector<double> current_elements;

	MedianStruct medianStruct = MedianStruct();

	for(auto &element: elements) {
		std::cout << "Adding element "<< element << std::endl;
		medianStruct.insertElement(element);
		std::cout << "Current median is " << medianStruct.getMedian();
		current_elements.push_back(element);
		double bf_median = bruteForceMedian(current_elements);
		REQUIRE( medianStruct.getMedian() == bf_median);
		std::cout << " == " << bf_median << ", same as brute force median!" << std::endl;

	}
}