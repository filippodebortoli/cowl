/// @author Ivano Bilenchi

#include "cowl_obj_prop_range_axiom_private.h"
#include "cowl_cls_exp.h"
#include "cowl_hash_utils.h"
#include "cowl_obj_prop_exp.h"

CowlObjPropExp const* cowl_obj_prop_range_axiom_get_prop(CowlObjPropRangeAxiom const *axiom) {
    return axiom->prop_exp;
}

CowlClsExp const* cowl_obj_prop_range_axiom_get_domain(CowlObjPropRangeAxiom const *axiom) {
    return axiom->domain;
}

bool cowl_obj_prop_range_axiom_equals(CowlObjPropRangeAxiom const *lhs,
                                       CowlObjPropRangeAxiom const *rhs) {
    return cowl_obj_prop_exp_equals(lhs->prop_exp, rhs->prop_exp) &&
           cowl_cls_exp_equals(lhs->domain, rhs->domain);
}

uint32_t cowl_obj_prop_range_axiom_hash(CowlObjPropRangeAxiom const *axiom) {
    return cowl_hash_2(COWL_HASH_INIT_OBJ_PROP_RANGE_AXIOM,
                       cowl_obj_prop_exp_hash(axiom->prop_exp),
                       cowl_cls_exp_hash(axiom->domain));
}
