module;
#include <stdlib.h>

module rng:impl;

namespace rng {
float randf() {
  return static_cast<float>(::rand()) / static_cast<float>(RAND_MAX);
}
unsigned rand(unsigned max) { return ::rand() % max; }
} // namespace rng
