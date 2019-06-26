/// @author Ivano Bilenchi

#include "cowl_sub_annot_prop_axiom_private.h"
#include "cowl_annot_prop.h"

static CowlSubAnnotPropAxiom* cowl_sub_annot_prop_axiom_alloc(CowlAnnotProp *sub,
                                                              CowlAnnotProp *super,
                                                              CowlAnnotationVec *annot) {
    cowl_uint_t hash = cowl_axiom_hash_2(COWL_HASH_INIT_SUB_ANNOT_PROP_AXIOM, annot,
                                         cowl_annot_prop_hash(sub),
                                         cowl_annot_prop_hash(super));

    CowlSubAnnotPropAxiom init = {
        .super = COWL_AXIOM_INIT(CAT_SUB_ANNOT_PROP, hash, annot),
        .sub_prop = cowl_annot_prop_retain(sub),
        .super_prop = cowl_annot_prop_retain(super)
    };

    cowl_struct(CowlSubAnnotPropAxiom) *axiom;
    cowl_axiom_alloc(axiom, init, annot);
    return axiom;
}

static void cowl_sub_annot_prop_axiom_free(CowlSubAnnotPropAxiom *axiom) {
    if (!axiom) return;
    cowl_annot_prop_release(axiom->sub_prop);
    cowl_annot_prop_release(axiom->super_prop);
    cowl_axiom_free(axiom);
}

CowlSubAnnotPropAxiom* cowl_sub_annot_prop_axiom_get(CowlAnnotProp *sub, CowlAnnotProp *super,
                                                     CowlAnnotationVec *annot) {
    return cowl_sub_annot_prop_axiom_alloc(sub, super, annot);
}

CowlSubAnnotPropAxiom* cowl_sub_annot_prop_axiom_retain(CowlSubAnnotPropAxiom *axiom) {
    return cowl_object_retain(axiom);
}

void cowl_sub_annot_prop_axiom_release(CowlSubAnnotPropAxiom *axiom) {
    if (axiom && !cowl_object_release(axiom)) {
        cowl_sub_annot_prop_axiom_free(axiom);
    }
}

CowlAnnotProp* cowl_sub_annot_prop_axiom_get_super(CowlSubAnnotPropAxiom *axiom) {
    return axiom->super_prop;
}

CowlAnnotProp* cowl_sub_annot_prop_axiom_get_sub(CowlSubAnnotPropAxiom *axiom) {
    return axiom->sub_prop;
}

CowlAnnotationVec* cowl_sub_annot_prop_axiom_get_annot(CowlSubAnnotPropAxiom *axiom) {
    return cowl_axiom_get_annot(axiom);
}

bool cowl_sub_annot_prop_axiom_equals(CowlSubAnnotPropAxiom *lhs, CowlSubAnnotPropAxiom *rhs) {
    return cowl_axiom_equals_impl(lhs, rhs,
                                  cowl_annot_prop_equals(lhs->super_prop, rhs->super_prop) &&
                                  cowl_annot_prop_equals(lhs->sub_prop, rhs->sub_prop));
}

cowl_uint_t cowl_sub_annot_prop_axiom_hash(CowlSubAnnotPropAxiom *axiom) {
    return cowl_object_hash_get(axiom);
}

bool cowl_sub_annot_prop_axiom_iterate_signature(CowlSubAnnotPropAxiom *axiom,
                                                 void *ctx, CowlEntityIterator iter) {
    if (!cowl_annot_prop_iterate_signature(axiom->super_prop, ctx, iter)) return false;
    if (!cowl_annot_prop_iterate_signature(axiom->sub_prop, ctx, iter)) return false;
    if (!cowl_axiom_annot_iterate_signature(axiom, ctx, iter)) return false;
    return true;
}