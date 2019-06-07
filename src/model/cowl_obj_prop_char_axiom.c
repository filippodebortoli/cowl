/// @author Ivano Bilenchi

#include "cowl_obj_prop_char_axiom_private.h"
#include "cowl_cls_exp_private.h"
#include "cowl_hash_utils.h"
#include "cowl_obj_prop_exp_private.h"

static CowlObjPropCharAxiom* cowl_obj_prop_char_axiom_alloc(CowlAxiomType type,
                                                            CowlObjPropExp *prop) {
    cowl_uint_t hash = cowl_hash_2(COWL_HASH_INIT_OBJ_PROP_CHAR_AXIOM, type,
                                   cowl_obj_prop_exp_hash(prop));

    CowlObjPropCharAxiom init = {
        .super = COWL_AXIOM_INIT(type, hash),
        .prop_exp = cowl_obj_prop_exp_retain(prop)
    };

    cowl_struct(CowlObjPropCharAxiom) *axiom = malloc(sizeof(*axiom));
    memcpy(axiom, &init, sizeof(*axiom));
    return axiom;
}

static void cowl_obj_prop_char_axiom_free(CowlObjPropCharAxiom *axiom) {
    if (!axiom) return;
    cowl_obj_prop_exp_release(axiom->prop_exp);
    free((void *)axiom);
}

CowlObjPropCharAxiom* cowl_obj_prop_char_axiom_get(CowlObjPropCharAxiomType type,
                                                   CowlObjPropExp *prop) {
    return cowl_obj_prop_char_axiom_alloc((CowlAxiomType)type + CAT_FUNCTIONAL_OBJ_PROP, prop);
}

CowlObjPropCharAxiom* cowl_obj_prop_char_axiom_retain(CowlObjPropCharAxiom *axiom) {
    return cowl_object_retain(axiom);
}

void cowl_obj_prop_char_axiom_release(CowlObjPropCharAxiom *axiom) {
    if (axiom && !cowl_object_release(axiom)) {
        cowl_obj_prop_char_axiom_free(axiom);
    }
}

CowlObjPropCharAxiomType cowl_obj_prop_char_axiom_get_type(CowlObjPropCharAxiom *axiom) {
    return (CowlObjPropCharAxiomType)(axiom->super.type - CAT_FUNCTIONAL_OBJ_PROP);
}

CowlObjPropExp* cowl_obj_prop_char_axiom_get_prop(CowlObjPropCharAxiom *axiom) {
    return axiom->prop_exp;
}

bool cowl_obj_prop_char_axiom_equals(CowlObjPropCharAxiom *lhs, CowlObjPropCharAxiom *rhs) {
    return (lhs->super.type == rhs->super.type &&
            cowl_obj_prop_exp_equals(lhs->prop_exp, rhs->prop_exp));
}

cowl_uint_t cowl_obj_prop_char_axiom_hash(CowlObjPropCharAxiom *axiom) {
    return cowl_object_hash_get(axiom);
}

bool cowl_obj_prop_char_axiom_iterate_signature(CowlObjPropCharAxiom *axiom,
                                                void *ctx, CowlEntityIterator iter) {
    return cowl_obj_prop_exp_iterate_signature(axiom->prop_exp, ctx, iter);
}
