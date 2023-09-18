#pragma leco tool
#include <stdio.h>

import rng;

int main() {
  using namespace rng;
  seed();

  random_picker<3> p;
  p[0] = p[1] = 20;
  p[2] = 30;

  unsigned x[3]{};
  for (auto i = 0; i < 100000; i++) {
    x[p.pick()]++;
  }
  for (auto i = 0; i < 3; i++) {
    printf("%d = %d -- %d\n", i, x[i], x[i] * 60 / 100000);
  }

  // Just test the link phase
  return randf() * rand(p.pick());
}
