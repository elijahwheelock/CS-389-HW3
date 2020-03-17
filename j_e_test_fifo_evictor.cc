#define CATCH_CONFIG_MAIN

#include <iostream>

#include "fifo_evictor.hh"
#include "catch2.hh"


TEST_CASE("Evictor works as described in fifo_evictor.hh", "[evictor]") {

  FifoEvictor e;

  SECTION("Evicting on an empty evictor should return an empty string") {
    REQUIRE(e.evict() == "");
  }

  SECTION("Evicting after touching a key should return that key."){
    e.touch_key("hello");
    REQUIRE(e.evict() == "hello");

    e.touch_key("world");
    REQUIRE(e.evict() == "world");

    REQUIRE(e.evict() == "");
  }

  SECTION("Insertion order should be respected in eviction order."){
    while (e.evict() != "") {};
    REQUIRE(e.evict() == "");

    e.touch_key("2");
    e.touch_key("3");
    e.touch_key("1");
    e.touch_key("4");

    REQUIRE(e.evict() == "2");
    REQUIRE(e.evict() == "3");
    REQUIRE(e.evict() == "1");
    REQUIRE(e.evict() == "4");
    REQUIRE(e.evict() == "");

  }

  SECTION("Insertion order should be respected in eviction order, even with duplicates."){
    while (e.evict() != "") {};
    REQUIRE(e.evict() == "");

    e.touch_key("2");
    e.touch_key("3");
    e.touch_key("2");
    e.touch_key("2");
    e.touch_key("1");
    e.touch_key("1");
    e.touch_key("4");

    REQUIRE(e.evict() == "2");
    REQUIRE(e.evict() == "3");
    REQUIRE(e.evict() == "2");
    REQUIRE(e.evict() == "2");
    REQUIRE(e.evict() == "1");
    REQUIRE(e.evict() == "1");
    REQUIRE(e.evict() == "4");
    REQUIRE(e.evict() == "");

  }

  SECTION("Emptying the cache between insertions should not change behavior."){
    while (e.evict() != "") {};

    e.touch_key("2");
    e.touch_key("3");
    e.touch_key("5");

    REQUIRE(e.evict() == "2");
    REQUIRE(e.evict() == "3");
    REQUIRE(e.evict() == "5");
    REQUIRE(e.evict() == "");

    e.touch_key("2");
    e.touch_key("1");
    e.touch_key("4");

    REQUIRE(e.evict() == "2");
    REQUIRE(e.evict() == "1");
    REQUIRE(e.evict() == "4");

    REQUIRE(e.evict() == "");
  }


  // SECTION("This should fail, for posterity."){
  //   e.touch_key("chicken");
  //   REQUIRE(e.evict() == "duck");
  // }

}
