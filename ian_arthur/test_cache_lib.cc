// A testfile
#include "cache.hh"
#include <cassert>
#include "fifo_evictor.hh"
#include "evictor.hh"
#include <iostream>
#include <cstring>

using byte_type = char;
using val_type = const byte_type*;   // Values for K-V pairs
using size_type = uint32_t;         // Internal indexing to K-V elements


bool test_set(Cache* test_cache, val_type test_val) {
	
	test_cache->set("Chilombo",test_val,2);
	size_type sz = 0;
	assert(test_cache->get("Chilombo",sz) == test_val);
	return true;
}

bool test_get(Cache* test_cache, val_type test_value){

	test_cache->set("Aiko",test_value,2);
	size_type sz = 0;
	assert(test_cache->get("Aiko",sz) == test_value);
	return true;
}

bool test_reset(Cache* test_cache, val_type test_val1, val_type test_val2) {
	
	test_cache->set("Porter",test_val1,2);
	test_cache->set("Shorter",test_val2,3);

	test_cache->reset();
	assert(test_cache->space_used() == 0);
	return true;
}

bool test_no_key(Cache* test_cache) {
	size_type sz = 0;
	std::cout << strcmp(test_cache->get("Taco",sz), "") <<"burrr"<< std::endl;
	assert(strcmp(test_cache->get("Taco",sz), "") == 0);
	return true;
}

bool test_changed_key(Cache* test_cache,val_type test_val1,val_type test_val2) {

	test_cache->set("Matrix",test_val1,2);
	test_cache->set("Matrix",test_val2,2);
	size_type sz = 0;
	assert(test_cache->get("Matrix",sz) == test_val2);
	return true;
}

bool test_changed_key_size(Cache* test_cache,val_type test_val1, val_type test_val2) {

	test_cache->set("AVG",test_val1,2);
	test_cache->set("AVG",test_val2,3);
	size_type sz  = 0;
	test_cache->get("AVG",sz);
	assert(sz == 3);
	return true;
}

bool test_evictor(Cache* test_cache,val_type test_val1,val_type test_val2,val_type test_val3) {
	
	test_cache->set("Macy",test_val1,3);
	test_cache->set("Eitan",test_val2,3);
	//this last value should cause us to evict because capacity = 10
	test_cache->set("Policy",test_val3,7);
	size_type sz = 0;
	assert(strcmp(test_cache->get("Macy",sz), "") == 0);

	return true;
}

bool test_space_used(Cache* test_cache,val_type test_val1,val_type test_val2,val_type test_val3) {
	test_cache->set("Toe",test_val1,1);
	test_cache->set("Uhh",test_val2,4);
	test_cache->set("Jesus",test_val3,1);
	assert(test_cache->space_used() == 6);
	return true;
}


//Run all test functions
int main() {

	
	
	//init evictor-less cache to test
	Cache* test_cache = new Cache(10);
	auto evictor = new FifoEvictor();
	Cache* test_cache_with_evictor = new Cache(10,0.75,evictor);

	//init byte_type values to be used
	//char array[] = "Run Me!";
	val_type value1 = "R";
	val_type value2 = "U";
	val_type value3 = "M";
	//Cache::byte_type value4 = 'f';
	//Cache::byte_type value5 = '>';
	//Cache::byte_type value6 = '@';

	//First test
	std::cout<<"Hi, I'm Dave"<< std::endl;
	if (test_set(test_cache,value1)) {
		
		std::cout << "Set function test passed!" << std::endl;
	}

	test_cache->reset(); 
	
	//Second test
	if (test_get(test_cache,value1)) {
		std::cout << "Get function test passed!" << std::endl;
	}
	test_cache->reset();

	//Third test
	if (test_reset(test_cache,value1,value2)) {
		std::cout << "Reset function test passed!" << std::endl;
	}
	test_cache->reset();

	//Fourth test
	if (test_no_key(test_cache)) {
		std::cout << "No key test passed!" << std::endl;
	}
	test_cache->reset();

	//Fifth test
	std::cout<<value1<< "fr this time"<<std::endl;
	if (test_changed_key(test_cache,value1,value2)) {
		std::cout << "Changed key test passed!" << std::endl;
	}
	test_cache->reset();

	//Sixth test
	if (test_changed_key_size(test_cache,value1,value2)) {
		std::cout << "Changed size test passed!" << std::endl;
	}
	test_cache->reset();

	//Seventh test
	if (test_evictor(test_cache_with_evictor,value1,value2,value3)) {
		std::cout << "Evicted key test passed!" << std::endl;
	}
	test_cache->reset();

	//Eighth test
	if (test_space_used(test_cache,value1,value2,value3)) {
		std::cout << "Space used function test passed!" << std::endl;
	}
	test_cache->reset();


	std::cout << "All tests passed! Fuck yeah!!" << std::endl;
	delete test_cache;
	delete test_cache_with_evictor;
	delete evictor;
	delete value1;
	delete value2;
	delete value3;

	return 1;
}
