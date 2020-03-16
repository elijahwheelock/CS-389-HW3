#define CATCH_CONFIG_MAIN

#include <iostream>

#include "fifo_evictor.hh"
#include "catch2.hh"


void reset() {
  while (e.evict() != "") {}
}

TEST_CASE("Evictor works as described in fifo_evictor.hh", "[evictor]") {
  FifoEvictor e;

  reset();
  REQUIRE(e.evict() == "");

  SECTION("basic functions"){
    e.touch_key("hello");
    REQUIRE(e.evict() == "hello");

    e.touch_key("world");
    REQUIRE(e.evict() == "world");

    REQUIRE(e.evict() == "");
  }


  SECTION("Ordered insertion and eviction, with duplicates"){
    reset();
    REQUIRE(e.evict() == "");

    e.touch_key("2");
    e.touch_key("3");
    e.touch_key("2");
    e.touch_key("2");
    e.touch_key("1");
    e.touch_key("4");

    REQUIRE(e.evict() == "2");
    REQUIRE(e.evict() == "3");
    REQUIRE(e.evict() == "2");
    REQUIRE(e.evict() == "2");
    REQUIRE(e.evict() == "1");
    REQUIRE(e.evict() == "4");
  }
}
