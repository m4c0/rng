#include "../ecow/ecow.hpp"

auto rng() {
  using namespace ecow;

  auto m = unit::create<mod>("rng");
  m->add_impl("impl");
  return m;
}
int main(int argc, char **argv) {
  using namespace ecow;

  auto poc = unit::create<app>("poc");
  poc->add_ref(rng());
  poc->add_unit<>("poc");
  return run_main(poc, argc, argv);
}
