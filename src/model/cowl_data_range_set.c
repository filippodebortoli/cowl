/// @author Ivano Bilenchi

#include "cowl_data_range_set.h"
#include "cowl_data_range.h"

UHASH_SET_IMPL(CowlDataRangeSet, CowlDataRange*, cowl_data_range_hash, cowl_data_range_equals)

void cowl_data_range_set_free(CowlDataRangeSet *set) {
    if (!set) return;
    uhash_foreach_key(CowlDataRangeSet, set, range, cowl_data_range_release(range));
    uhash_free(CowlDataRangeSet, (UHash(CowlDataRangeSet) *)set);
}

bool cowl_data_range_set_equals(CowlDataRangeSet *lhs, CowlDataRangeSet *rhs) {
    return uhset_equals(CowlDataRangeSet, lhs, rhs);
}

cowl_uint_t cowl_data_range_set_hash(CowlDataRangeSet *set) {
    return uhset_hash(CowlDataRangeSet, set);
}

bool cowl_data_range_set_iterate_signature(CowlDataRangeSet *set, void *ctx,
                                           CowlEntityIterator iter) {
    uhash_foreach_key(CowlDataRangeSet, set, range, {
        if (!cowl_data_range_iterate_signature(range, ctx, iter)) return false;
    });
    return true;
}
