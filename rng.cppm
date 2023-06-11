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

class it {
  unsigned *m_w;
  unsigned *m_sum;

public:
  explicit constexpr it(unsigned *w, unsigned *s) : m_w{w}, m_sum{s} {}

  it &operator=(unsigned w) {
    *m_sum += w;
    *m_sum -= *m_w;
    *m_w = w;
    return *this;
  }
};
export template <unsigned MaxElems> class random_picker {
  static constexpr const auto max_elems = MaxElems;

  unsigned m_weights[max_elems]{};
  unsigned m_sum{};

public:
  [[nodiscard]] constexpr auto operator[](unsigned elem) noexcept {
    return it{&m_weights[elem], &m_sum};
  }

  [[nodiscard]] unsigned pick() const noexcept {
    auto r = rng::rand(max_elems);
    for (auto i = 0; i < max_elems; i++) {
      auto w = m_weights[i];
      if (w < r)
        return i;
      r -= w;
    }
    // This should never happen
    return max_elems - 1;
  }
};
} // namespace rng
