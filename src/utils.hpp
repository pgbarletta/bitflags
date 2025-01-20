#include <cxxabi.h>
#include <string_view>
#include <type_traits>
#include <typeinfo>

template <typename T> constexpr auto type_name() {
    constexpr auto prefix = std::string_view{"[with T = "};
    constexpr auto suffix = std::string_view{"]"};
    constexpr auto function = std::string_view{__PRETTY_FUNCTION__};

    constexpr auto start = function.find(prefix) + prefix.size();
    constexpr auto end = function.rfind(suffix);
    constexpr auto name = function.substr(start, end - start);
    return name;
}
