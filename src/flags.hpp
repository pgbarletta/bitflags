#include <cstdint>
#include <string>
#include <string_view>

#include <fmt/format.h>

using namespace std::string_view_literals; // Enables sv suffix only

enum class BitFlagREAF : uint64_t {
    reaf_nonreaf_flag = 1,
    reaf_reaf_flag = 2,
    reaf_bond_flag = 3,
    reaf_angle_flag = 4,
    reaf_dihedral_flag = 5,
    reaf_torsion_flag = 6,
    reaf_rotamer_flag = 7,
    reaf_ele_flag = 8,
    reaf_vdw_flag = 9,
    reaf_ele14_flag = 10,
    reaf_vdw14_flag = 11,
};

template <> struct fmt::formatter<BitFlagREAF> : formatter<std::string_view> {
    auto format(const BitFlagREAF &f,
                fmt::format_context &ctx) const -> fmt::format_context::iterator;
};