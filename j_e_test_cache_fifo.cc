#include <cassert>
#include <iostream>
#include <cstring>

#include "fifo_evictor.hh"
#include "cache.hh"


fifo_evictor* fifo_p = new fifo_evictor();

Cache c(32, 0.75, fifo_p);


s

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
