#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "RightAngled_open.cpp"
#include "RightAngled_open.hpp"
#include "Triangle.cpp"
#include "Triangle.hpp"

TEST_CASE( "Arguments initialized") {
    RightAngled_open t1;
    t1.set_a(20);
    t1.set_b(12);
    t1.set_c(16);

    REQUIRE( t1.perimeter() == 48);
}
