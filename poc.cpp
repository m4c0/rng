import rng;

// Just testing the link phase
int main() {
  using namespace rng;
  seed();

  random_picker<3> p;
  p[0] = 10;
  p[1] = 20;
  p[2] = 30;

  return randf() * rand(p.pick());
}
