#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "print.hpp"

TEST_CASE("Prints hello world") {
	REQUIRE(printHelloWorld() == "Hello World!");
}