#define CATCH_CONFIG_MAIN

#include <iostream>
#include <cstring>

#include "evictor.hh"
#include "cache.hh"
#include "catch2.hh"

TEST_CASE("test set" "[set]") {
  Cache c(16);
  Cache::val_type result;
  Cache::size_type val_size = 0;

  SECTION( "Cache::get on empty cache returns nullptr" ) {
    REQUIRE(c.get("1", val_size) == nullptr);
  }

  SECTION( "Cache::get returns the value set for the key" ) {
    c.set("1", "first", 6);
    c.set("2", "second", 7);
    result = c.get("1", val_size);
    REQUIRE(result != nullptr);
    REQUIRE(std::strcmp(result, "first") == 0);
    result = c.get("2", val_size);
    REQUIRE(result != nullptr);
    REQUIRE(std::strcmp(result, "second") == 0);
  }

  SECTION( "Cache::set performs a deep copy" ) {
    Cache::val_type first = "first";
    c.set("1", "first", 6);
    first = "nothing";
    REQUIRE(c.space_used() == 6);
  }

  SECTION( "successive sets to different keys increase space_used" ) {
    c.set("1", "first", 6);
    c.set("2", "second", 7);
    REQUIRE(c.space_used() == 13);
  }

  SECTION( "Cache::get updates its second argument to the size of the requested element" ) {
    c.set("2", "second", 7);
    result = c.get("2", val_size);
    REQUIRE(val_size == 7);
  }

  SECTION( "insertions that would go over max_size fail" ) {
    c.set("1", "first", 6);
    c.set("2", "second", 7);
    c.set("3", "third", 6);
    result = c.get("3", val_size);
    REQUIRE(result == nullptr);
    REQUIRE(c.space_used() == 13);
  }

  SECTION( "subsequent writes to same key overwrite" ) {
    c.set("1", "first", 6);
    c.set("1", "fourth", 7);

    REQUIRE(c.space_used() == 7);
    result = c.get("1", val_size);
    REQUIRE(result != nullptr);
    REQUIRE(std::strcmp(result, "fourth") == 0);
    REQUIRE(val_size == 7);
  }

  SECTION( "oversized insertions fail" ) {
    c.set("121", "hundred-twenty-first", 21);
    REQUIRE(c.space_used() == 0);
    result = c.get("121", val_size);
    REQUIRE(result == nullptr);
  }

  SECTION( "Cache::del fails on absent keys" ) {
    REQUIRE(c.del("1") == false);
  }

  SECTION( "Cache::del renders the deleted element inaccessible" ) {
    c.set("1", "first", 6);
    c.set("2", "second", 7);
    REQUIRE(c.del("1") == true);
    REQUIRE(c.get("1", val_size) == nullptr);
    REQUIRE(c.space_used() == 7);
  }

  SECTION( "Cache::reset renders all elements inaccessible, zeros space_used" ) {
    c.set("1", "first", 6);
    c.set("2", "second", 7);
    c.reset();
    REQUIRE(c.get("1", val_size) == nullptr);
    REQUIRE(c.get("2", val_size) == nullptr);
    REQUIRE(c.space_used() == 0);
  }
}
