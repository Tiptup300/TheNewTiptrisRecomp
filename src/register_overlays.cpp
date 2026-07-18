// Registers the recompiled section/overlay table with librecomp.
// The generated recomp_overlays.inl defines section_table[], num_sections,
// and overlay_sections_by_index[].
#include "../RecompiledFuncs/recomp_overlays.inl"

#include "librecomp/overlays.hpp"

namespace tnt { void register_overlays(); }

void tnt::register_overlays() {
    recomp::overlays::overlay_section_table_data_t sections {
        .code_sections = section_table,
        .num_code_sections = ARRLEN(section_table),
        .total_num_sections = num_sections,
    };

    recomp::overlays::overlays_by_index_t overlays {
        .table = overlay_sections_by_index,
        .len = ARRLEN(overlay_sections_by_index),
    };

    recomp::overlays::register_overlays(sections, overlays);
}
