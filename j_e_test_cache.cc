#include <iostream>
#include <cstring>

#include "evictor.hh"
#include "cache.hh"
#include "catch2.hh"
#define CATCH_CONFIG_MAIN

TEST_CASE("test set" "[set]") {
  Cache c(16);
  Cache::val_type result;
  Cache::size_type val_size = 0;
  
  SECTION( "Cache::get on empty cache returns nullptr" ) {
    REQUIRE(c.get("1", val_size) == nullptr);
  }

  SECTION( "Cache::get after Cache::set returns the same key" ) {
    c.set("1", "first", 6);
    result = c.get("1", val_size);
    REQUIRE(result != nullptr);
    REQUIRE(std::strcmp(result, "first") == 0);
  }

  SECTION( "Cache::set performs a deep copy" ) {
    key_type "1" = "1";
    Cache::val_type first = "first";
    c.set("1", first, 6);
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

  SECTION( "Cache::del renders the deleted element inaccessible" ) {
    c.set("1", "first", 6);
    c.set("2", "second", 7);
    REQUIRE(c.del("1") == true);
    REQUIRE(c.get("1", val_size) == nullptr);
    REQUIRE(c.space_used() == 7);
  }
}

void test_del(){

  Cache::val_type first = "first";
  Cache::val_type second  = "second";


  Cache::size_type val_size = 0;

  c.set("1", first, 6);
  c.set("2", second, 7);

  Cache::val_type result = c.get("1", val_size);
  REQUIRE(result != nullptr);
  REQUIRE(std::strcmp(result, "first") == 0);
  REQUIRE(val_size == 6);

  REQUIRE(c.del("1") == true);
  REQUIRE(c.space_used() == 7);

  REQUIRE(c.get("1", val_size) == nullptr);
  REQUIRE(c.del("1") == false);

  REQUIRE(c.space_used() == 7);

}


void test_reset(){

  Cache::val_type first = "first";
  Cache::val_type second  = "second";
  Cache::val_type third   = "th";

  key_type "1" = "1";
  key_type "2" = "2";
  key_type third_key = "3";

  Cache::size_type val_size = 0;

  c.set("1", first, 6);
  c.set("2", second, 7);
  c.set(third_key, third, 3);

  Cache::val_type result = c.get("1", val_size);
  REQUIRE(result != nullptr);
  REQUIRE(std::strcmp(result, "first") == 0);
  REQUIRE(c.space_used() == 16);

  c.reset();

  REQUIRE(c.get("1", val_size) == nullptr);
  REQUIRE(val_size == 6);

  REQUIRE(c.get("2", val_size) == nullptr);
  REQUIRE(val_size == 6);

  REQUIRE(c.del(third_key) == false);
  REQUIRE(c.space_used() == 0);

}


int main() {

  test_set_and_get();
  c.reset();
  test_del();
  c.reset();
  test_reset();
  c.reset();

  std::cout << "All cache tests passing with no evictor. \n";

  return 0;
}
