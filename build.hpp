#include "../ecow/ecow.hpp"

auto rng() {
  using namespace ecow;
  return unit::create<mod>("rng");
}
