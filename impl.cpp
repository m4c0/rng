module;
#include <stdlib.h>
#include <time.h>

module rng;

namespace rng {
void seed() { srand(time(0)); }
void seed(unsigned s) { srand(s); }
float randf() {
  return static_cast<float>(::rand()) / static_cast<float>(RAND_MAX);
}
unsigned rand(unsigned max) { return ::rand() % max; }
unsigned rand_i(unsigned max) { return ::rand() % (max + 1); }
} // namespace rng
