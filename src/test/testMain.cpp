#include <cstdlib>
#include "algo.hpp"

// Include Catch2 - Simple as this
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Sorting test", "[sort]") {
    int unsortedIntegers[100];

    SECTION("insertionSort") {
	// Generate random array
	for(int iter = 0; iter < sizeof(unsortedIntegers)/sizeof(int); iter++)
	    unsortedIntegers[iter] = rand();

	Sort::insertionSort(unsortedIntegers, sizeof(unsortedIntegers)/sizeof(int));
	for(int iter = 0; iter < (sizeof(unsortedIntegers)/sizeof(int) - 1); iter++)
	    REQUIRE(unsortedIntegers[iter] <= unsortedIntegers[iter+1]);
    }

    SECTION("selectionSort") {
	// Generate random array
	for(int iter = 0; iter < sizeof(unsortedIntegers)/sizeof(int); iter++)
	    unsortedIntegers[iter] = rand();

	Sort::selectionSort(unsortedIntegers, sizeof(unsortedIntegers)/sizeof(int));
	for(int iter = 0; iter < (sizeof(unsortedIntegers)/sizeof(int) - 1); iter++)
	    REQUIRE(unsortedIntegers[iter] <= unsortedIntegers[iter+1]);
    }
}

TEST_CASE("Searching test", "[search]") {
    // Integer search test
    int intgerData[500] = {100, 40, 12, 98, 56, 44, 19, 52, 82};
    REQUIRE(Search::linearSearch(intgerData,
		sizeof(intgerData)/sizeof(int), 44) == 5);
}

