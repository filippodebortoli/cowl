/// @author Ivano Bilenchi

#include "cowl_nary_cls_axiom_private.h"
#include "cowl_cls_exp.h"
#include "cowl_cls_exp_set.h"
#include "cowl_hash_utils.h"

static CowlNAryClsAxiom* cowl_nary_cls_axiom_alloc(CowlAxiomType type, CowlClsExpSet *classes) {
    cowl_uint_t hash = cowl_hash_2(COWL_HASH_INIT_NARY_CLS_AXIOM, type,
                                   uhset_hash(CowlClsExpSet, classes));

    CowlNAryClsAxiom init = {
        .super = COWL_AXIOM_INIT(type, hash),
        .classes = classes
    };

    cowl_struct(CowlNAryClsAxiom) *axiom = malloc(sizeof(*axiom));
    memcpy(axiom, &init, sizeof(*axiom));
    return axiom;
}

static void cowl_nary_cls_axiom_free(CowlNAryClsAxiom *axiom) {
    if (!axiom) return;
    cowl_cls_exp_set_free(axiom->classes);
    free((void *)axiom);
}

CowlNAryClsAxiom* cowl_nary_cls_axiom_get(CowlNAryAxiomType type, CowlClsExpSet *classes) {
    return cowl_nary_cls_axiom_alloc((CowlAxiomType)type + CAT_EQUIVALENT_CLASSES, classes);
}

CowlNAryClsAxiom* cowl_nary_cls_axiom_retain(CowlNAryClsAxiom *axiom) {
    return cowl_object_retain(axiom);
}

void cowl_nary_cls_axiom_release(CowlNAryClsAxiom *axiom) {
    if (axiom && !cowl_object_release(axiom)) {
        cowl_nary_cls_axiom_free(axiom);
    }
}

CowlNAryAxiomType cowl_nary_cls_axiom_get_type(CowlNAryClsAxiom *axiom) {
    return (CowlNAryAxiomType)(axiom->super.type - CAT_EQUIVALENT_CLASSES);
}

CowlClsExpSet *cowl_nary_cls_axiom_get_classes(CowlNAryClsAxiom *axiom) {
    return axiom->classes;
}

bool cowl_nary_cls_axiom_equals(CowlNAryClsAxiom *lhs, CowlNAryClsAxiom *rhs) {
    return (lhs->super.type == rhs->super.type &&
            uhset_equals(CowlClsExpSet, lhs->classes, rhs->classes));
}

cowl_uint_t cowl_nary_cls_axiom_hash(CowlNAryClsAxiom *axiom) {
    return cowl_object_hash_get(axiom);
}

bool cowl_nary_cls_axiom_iterate_signature(CowlNAryClsAxiom *axiom, void *ctx,
                                           CowlEntityIterator iter) {
    uhash_foreach_key(CowlClsExpSet, axiom->classes, exp, {
        if (!cowl_cls_exp_iterate_signature(exp, ctx, iter)) return false;
    });
    return true;
}
