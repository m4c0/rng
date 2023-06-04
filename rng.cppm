export module rng;

namespace rng {
export void seed();
export void seed(unsigned s);
export unsigned rand(unsigned max);
export float randf();

export class randomizer {
  unsigned x = 0x69696969;

public:
  [[nodiscard]] constexpr auto random(unsigned max) {
    if consteval {
      /* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
      x ^= x << 13;
      x ^= x >> 17;
      x ^= x << 5;
      return x % max;
    } else {
      return static_cast<unsigned>(rand(max));
    }
  }
};
} // namespace rng
