#pragma leco add_impl impl
export module rng;
import hai;

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

  void set_value(unsigned w) {
    *m_sum += w;
    *m_sum -= *m_w;
    *m_w = w;
  }

public:
  explicit constexpr it(unsigned *w, unsigned *s) : m_w{w}, m_sum{s} {}

  it &operator=(unsigned w) {
    set_value(w);
    return *this;
  }

  // TODO: rule of five
  it &operator=(const it &o) {
    set_value(*o.m_w);
    return *this;
  }
};
export class random_picker {
  hai::array<unsigned> m_weights{};
  unsigned m_sum{};

public:
  constexpr random_picker() = default;
  constexpr random_picker(unsigned max_elems, unsigned init_w = 0)
      : m_weights{max_elems} {
    for (auto &w : m_weights) {
      w = init_w;
    }
    m_sum = max_elems * init_w;
  }

  [[nodiscard]] constexpr auto operator[](unsigned elem) noexcept {
    return it{&m_weights[elem], &m_sum};
  }

  [[nodiscard]] unsigned pick() const noexcept {
    auto r = rng::rand(m_sum);
    for (auto i = 0; i < m_weights.size(); i++) {
      auto w = m_weights[i];
      if (w > r)
        return i;
      r -= w;
    }
    // This should never happen
    return m_weights.size() - 1;
  }
};
} // namespace rng
