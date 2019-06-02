/// @author Ivano Bilenchi

#include "cowl_obj_has_self_private.h"
#include "cowl_hash_utils.h"
#include "cowl_obj_prop_exp.h"

static CowlObjHasSelf* cowl_obj_has_self_alloc(CowlObjPropExp *prop) {
    cowl_uint_t hash = cowl_hash_1(COWL_HASH_INIT_OBJ_HAS_SELF, cowl_obj_prop_exp_hash(prop));

    CowlObjHasSelf init = {
        .super = COWL_CLS_EXP_INIT(CCET_OBJ_HAS_SELF, hash),
        .prop = cowl_obj_prop_exp_retain(prop)
    };

    cowl_struct(CowlObjHasSelf) *exp = malloc(sizeof(*exp));
    memcpy(exp, &init, sizeof(*exp));
    return exp;
}

static void cowl_obj_has_self_free(CowlObjHasSelf *exp) {
    if (!exp) return;
    cowl_obj_prop_exp_release(exp->prop);
    free((void *)exp);
}

CowlObjHasSelf* cowl_obj_has_self_get(CowlObjPropExp *prop) {
    return cowl_obj_has_self_alloc(prop);
}

CowlObjHasSelf* cowl_obj_has_self_retain(CowlObjHasSelf *exp) {
    return cowl_cls_exp_ref_incr(exp);
}

void cowl_obj_has_self_release(CowlObjHasSelf *exp) {
    if (exp && !cowl_cls_exp_ref_decr(exp)) {
        cowl_obj_has_self_free(exp);
    }
}

CowlObjPropExp* cowl_obj_has_self_get_prop(CowlObjHasSelf *exp) {
    return exp->prop;
}

bool cowl_obj_has_self_equals(CowlObjHasSelf *lhs, CowlObjHasSelf *rhs) {
    return cowl_obj_prop_exp_equals(lhs->prop, rhs->prop);
}

cowl_uint_t cowl_obj_has_self_hash(CowlObjHasSelf *exp) {
    return cowl_cls_exp_hash_get(exp);
}

bool cowl_obj_has_self_iterate_signature(CowlObjHasSelf *exp, void *ctx, CowlEntityIterator iter) {
    return cowl_obj_prop_exp_iterate_signature(exp->prop, ctx, iter);
}