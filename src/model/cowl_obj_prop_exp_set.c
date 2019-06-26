/// @author Ivano Bilenchi

#include "cowl_obj_prop_exp_set.h"
#include "cowl_obj_prop_exp.h"

UHASH_SET_IMPL(CowlObjPropExpSet, CowlObjPropExp*,
               cowl_obj_prop_exp_hash, cowl_obj_prop_exp_equals)

void cowl_obj_prop_exp_set_free(CowlObjPropExpSet *set) {
    if (!set) return;
    uhash_foreach_key(CowlObjPropExpSet, set, exp, cowl_obj_prop_exp_release(exp));
    uhash_free(CowlObjPropExpSet, (UHash(CowlObjPropExpSet) *)set);
}

bool cowl_obj_prop_exp_set_equals(CowlObjPropExpSet *lhs, CowlObjPropExpSet *rhs) {
    return uhset_equals(CowlObjPropExpSet, lhs, rhs);
}

cowl_uint_t cowl_obj_prop_exp_set_hash(CowlObjPropExpSet *set) {
    return uhset_hash(CowlObjPropExpSet, set);
}

bool cowl_obj_prop_exp_set_iterate_signature(CowlObjPropExpSet *set, void *ctx,
                                             CowlEntityIterator iter) {
    uhash_foreach_key(CowlObjPropExpSet, set, prop, {
        if (!cowl_obj_prop_exp_iterate_signature(prop, ctx, iter)) return false;
    });
    return true;
}
