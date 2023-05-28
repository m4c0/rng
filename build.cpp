#include "../ecow/ecow.hpp"

int main(int argc, char **argv) {
  using namespace ecow;

  auto m = unit::create<mod>("rng");

  return run_main(m, argc, argv);
}
