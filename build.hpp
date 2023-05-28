#include "../ecow/ecow.hpp"

auto rng() {
  using namespace ecow;

  auto m = unit::create<mod>("rng");
  m->add_impl("impl");
  return m;
}
