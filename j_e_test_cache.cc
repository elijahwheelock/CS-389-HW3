#include <iostream>
#include <cstring>

#include "evictor.hh"
#include "cache.hh"
#include "catch2.hh"
#define CATCH_CONFIG_MAIN

TEST_CASE("test set" "[set]") {
  Cache c(16);
  
  SECTION( "Cache::get on empty cache returns nullptr" ) {
    REQUIRE(c.get(first_key, val_size) == nullptr);
  }
  SECTION( "Cache::set performs a deep copy" ) {
    Cache::val_type first = "first";
    key_type first_key = "1";
    c.set(first_key, first, 6);
    first_key = "1232";
    first = "nothing";
    REQUIRE(c.space_used() == 6);
  }
  SECTION( "Cache::get after Cache::set returns the same key" ) {
    c.set(first_key, first, 6);
    result = c.get(first_key, val_size);
    REQUIRE(result != nullptr);
    REQUIRE(std::strcmp(result, "first") == 0);

  }
  SECTION( "" ) {

  }
  SECTION( "" ) {

  }
}

void test_set_and_get(){

  Cache::val_type first   = "first";
  Cache::val_type second  = "second";
  Cache::val_type third   = "third";
  Cache::val_type fourth  = "fourth";

  key_type first_key  = "1";
  key_type second_key = "2";
  key_type third_key  = "3";
  key_type fourth_key = "4";

  Cache::val_type result;


  Cache::size_type val_size = 0;

  c.set(first_key, first, 6);

  first = "nothing";
  REQUIRE(c.space_used() == 6);

  result = c.get(first_key, val_size);
  REQUIRE(result != nullptr);
  REQUIRE(std::strcmp(result, "first") == 0);
  REQUIRE(val_size == 6);

  c.set(second_key, second, 7);

  second = "nothing";
  REQUIRE(c.space_used() == 13);

  result = c.get(second_key, val_size);
  REQUIRE(result != nullptr);
  REQUIRE(std::strcmp(result, "second") == 0);
  REQUIRE(val_size == 7);

  c.set(third_key, third, 6);
  //this should not be inserted.
  result = c.get(third_key, val_size);
  REQUIRE(result == nullptr);
  REQUIRE(val_size == 7);
  REQUIRE(c.space_used() == 13);

  //this should overwrite the value stored at key first_key
  c.set(first_key, fourth, 7);

  REQUIRE(c.space_used() == 14);
  result = c.get(first_key, val_size);
  REQUIRE(result != nullptr);
  REQUIRE(std::strcmp(result, "fourth") == 0);
  REQUIRE(val_size == 7);

}


void test_del(){

  Cache::val_type first = "first";
  Cache::val_type second  = "second";

  key_type first_key = "1";
  key_type second_key = "2";

  Cache::size_type val_size = 0;

  c.set(first_key, first, 6);
  c.set(second_key, second, 7);

  Cache::val_type result = c.get(first_key, val_size);
  REQUIRE(result != nullptr);
  REQUIRE(std::strcmp(result, "first") == 0);
  REQUIRE(val_size == 6);

  REQUIRE(c.del(first_key) == true);
  REQUIRE(c.space_used() == 7);

  REQUIRE(c.get(first_key, val_size) == nullptr);
  REQUIRE(c.del(first_key) == false);

  REQUIRE(c.space_used() == 7);

}


void test_reset(){

  Cache::val_type first = "first";
  Cache::val_type second  = "second";
  Cache::val_type third   = "th";

  key_type first_key = "1";
  key_type second_key = "2";
  key_type third_key = "3";

  Cache::size_type val_size = 0;

  c.set(first_key, first, 6);
  c.set(second_key, second, 7);
  c.set(third_key, third, 3);

  Cache::val_type result = c.get(first_key, val_size);
  REQUIRE(result != nullptr);
  REQUIRE(std::strcmp(result, "first") == 0);
  REQUIRE(c.space_used() == 16);

  c.reset();

  REQUIRE(c.get(first_key, val_size) == nullptr);
  REQUIRE(val_size == 6);

  REQUIRE(c.get(second_key, val_size) == nullptr);
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
