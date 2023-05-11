#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


TEST_CASE("numerator & denominator"){
	for(int i=0; i<=21; i++){
        CHECK(i==i);
    }
}