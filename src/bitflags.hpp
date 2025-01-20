#include <array>
#include <bit>
#include <bitset>
#include <concepts>
#include <cstdint>
#include <string>
#include <string_view>
#include <type_traits>

#include <fmt/format.h>
#include <magic_enum/magic_enum.hpp>

template <typename T>
concept EnumType = std::is_scoped_enum_v<T> || std::is_enum_v<T>;

template <typename T>
concept ArrayType = requires(T t) {
    typename T::value_type;
    typename T::size_type;
    requires std::is_same_v<T, std::array<typename T::value_type, T::size_type>>;
};

template <EnumType T> class BitFlags {
  public:
    explicit constexpr BitFlags() noexcept : _flags(0) {}

    explicit constexpr BitFlags(T const pos) noexcept : _flags(static_cast<size_t>(pos)) {}

    template <EnumType... Flags> explicit constexpr BitFlags(Flags... flags) noexcept : _flags(0) {
        (_flags.set(static_cast<size_t>(flags)), ...);
    }

    const bool operator[](T pos) const { return _flags[static_cast<size_t>(pos)]; }

    constexpr void operator[](T pos) { _flags[static_cast<size_t>(pos)] = true; }

    constexpr void set(T pos) { _flags[pos] = 1; }

    void reset() { _flags.reset(); }

    size_t nbits() const { return _nbits; }

    friend struct fmt::formatter<BitFlags<T>>;

  private:
    std::bitset<magic_enum::enum_count<T>()> _flags;
    size_t const _nbits = magic_enum::enum_count<T>();
};

template <EnumType T> struct fmt::formatter<BitFlags<T>> : formatter<std::string> {
    auto format(const BitFlags<T> &f,
                fmt::format_context &ctx) const -> fmt::format_context::iterator {
        std::string name = "";
        std::array<T, magic_enum::enum_count<T>()> const flags_values =
            magic_enum::enum_values<T>();
        for (auto const each : flags_values) {
            if (f[each]) {
                name += fmt::format("{}, ", each);
            }
        }
        if (!name.empty()) {
            name.pop_back();
            name.pop_back();
        }
        return formatter<std::string>::format(name, ctx);
    }
};
