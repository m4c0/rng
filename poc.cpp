import rng;

// Just testing the link phase
int main() {
  using namespace rng;
  seed();
  return randf() * rand(10);
}
