#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ranges>
#include <type_traits>
#include <vector>

#include <fmt/format.h>

#include "bitflags.hpp"
#include "flags.hpp"
#include "utils.hpp"

#define VSCALE (1ll << 40)
#define ESCALE (1ll << 30)
#define PMEDouble double

double conv(unsigned long long val) {

    printf("size: %lu\n", sizeof(long long));

    double energy = 0.0;
    double factor = 1.0 / ESCALE;
    if (val >= 0x8000000000000000ull) {
        energy = -(PMEDouble)(val ^ 0xffffffffffffffffull) * factor;
        printf("negativo energy: %g\n", energy);
    } else {
        energy = (PMEDouble)val * factor;
        printf("energy: %g\n", energy);
    }
    return energy;
}

int main(int argc, char *argv[]) {
    conv(58031069538ull);
    // unsigned long long int val = 775088296837ull;

    namespace vie = std::ranges::views;
    namespace ran = std::ranges;

    BitFlags<BitFlagREAF> nb_flags{BitFlagREAF::reaf_angle_flag, BitFlagREAF::reaf_bond_flag,
                                   BitFlagREAF::reaf_dihedral_flag};

    auto const _flag_names = magic_enum::enum_names<BitFlagREAF>();

    fmt::println("enum count: {}", magic_enum::enum_count<BitFlagREAF>());

    fmt::println("flag: {}", nb_flags);

    std::vector v{1, 2, 3, 4, 5, 6};

    auto sal = v | vie::filter([](int const i) { return i % 2 == 0; }) |
               vie::transform([](int const i) { return i * i; });

    ran::for_each(sal, [](int const i) { fmt::println("sal: {}", i); });

    fmt::println("size: {}", sizeof(nb_flags));

    // fmt::println("size: {}", );

    return 0;
}
