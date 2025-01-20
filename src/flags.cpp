#include "flags.hpp"

auto fmt::formatter<BitFlagREAF>::format(const BitFlagREAF &f, fmt::format_context &ctx) const
    -> fmt::format_context::iterator {
    string_view name = "unknown";
    switch (f) {
    case BitFlagREAF::reaf_nonreaf_flag:
        name = "reaf_nonreaf_flag";
        break;
    case BitFlagREAF::reaf_reaf_flag:
        name = "reaf_reaf_flag";
        break;
    case BitFlagREAF::reaf_bond_flag:
        name = "reaf_bond_flag";
        break;
    case BitFlagREAF::reaf_angle_flag:
        name = "reaf_angle_flag";
        break;
    case BitFlagREAF::reaf_dihedral_flag:
        name = "reaf_dihedral_flag";
        break;
    case BitFlagREAF::reaf_torsion_flag:
        name = "reaf_torsion_flag";
        break;
    case BitFlagREAF::reaf_rotamer_flag:
        name = "reaf_rotamer_flag";
        break;
    case BitFlagREAF::reaf_ele_flag:
        name = "reaf_ele_flag";
        break;
    case BitFlagREAF::reaf_vdw_flag:
        name = "reaf_vdw_flag";
        break;
    case BitFlagREAF::reaf_ele14_flag:
        name = "reaf_ele14_flag";
        break;
    case BitFlagREAF::reaf_vdw14_flag:
        name = "reaf_vdw14_flag";
        break;
    }
    return formatter<string_view>::format(name, ctx);
}