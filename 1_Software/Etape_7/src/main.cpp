#include "PGCD.hpp"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"



TEST_CASE("Fonctionnement normal", "[PGCD]"){
	
	SECTION("A > B"){
		REQUIRE( PGCD(34407, 11375) == 1);
		REQUIRE( PGCD(56546,2450) == 98);
		REQUIRE( PGCD(57998,12016) == 2);
		REQUIRE( PGCD(12222, 8739) == 9);
		REQUIRE( PGCD(23, 17) == 6); //false
	}

	SECTION("A < B"){
		REQUIRE( PGCD(297,60226) == 1);
		REQUIRE( PGCD(24972, 38880) == 12);
		REQUIRE( PGCD(47293, 53116) == 1);
		REQUIRE( PGCD(51642, 56905) == 19);
		REQUIRE( PGCD(23, 28) == 23); //false
	}

	SECTION("A = B"){
		REQUIRE( PGCD(35419,35419) == 35419);
		REQUIRE( PGCD(24972, 24972) == 24972);
		REQUIRE( PGCD(826, 826) == 826);
		REQUIRE( PGCD(23, 23) == 23);
		REQUIRE( PGCD(23, 23) == 123); //false
	}
	
    
}

TEST_CASE("Cas particuliers", "[PGCD]"){
	
	SECTION("A > B"){
		REQUIRE( PGCD(123, 0) == 123);
		REQUIRE( PGCD(123, 0) == 0); //false
		REQUIRE( PGCD(47, 0) == 47);
		REQUIRE( PGCD(65535,12016) == 1);
		REQUIRE( PGCD(65535, 45789) == 3);
	}

	SECTION("A < B"){
		REQUIRE( PGCD(0,60226) == 60226);
		REQUIRE( PGCD(0, 38880) == 38880);
		REQUIRE( PGCD(0, 128) == 123); // false
		REQUIRE( PGCD(47293, 65535) == 1);
		REQUIRE( PGCD(51642, 65535) == 3);
	}

	SECTION("A = B"){
		REQUIRE( PGCD(0,0) == 0);
		REQUIRE( PGCD(65535, 65535) == 65535);
		REQUIRE( PGCD(0, 0) == 123); //false
	}   
}
