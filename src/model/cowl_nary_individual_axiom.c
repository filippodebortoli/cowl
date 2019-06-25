/// @author Ivano Bilenchi

#include "cowl_nary_individual_axiom_private.h"
#include "cowl_individual_set.h"

static CowlNAryIndividualAxiom* cowl_nary_individual_axiom_alloc(CowlAxiomType type,
                                                                 CowlIndividualSet *operands,
                                                                 CowlAnnotationVec *annot) {
    cowl_uint_t hash = cowl_axiom_hash_2(COWL_HASH_INIT_NARY_IND_AXIOM, annot, type,
                                         cowl_individual_set_hash(operands));

    CowlNAryIndividualAxiom init = {
        .super = COWL_AXIOM_INIT(type, hash, annot),
        .operands = operands
    };

    cowl_struct(CowlNAryIndividualAxiom) *axiom;
    cowl_axiom_alloc(axiom, init, annot);
    return axiom;
}

static void cowl_nary_individual_axiom_free(CowlNAryIndividualAxiom *axiom) {
    if (!axiom) return;
    cowl_individual_set_free(axiom->operands);
    cowl_axiom_free(axiom);
}

CowlNAryIndividualAxiom* cowl_nary_individual_axiom_get(CowlNAryAxiomType type,
                                                        CowlIndividualSet *operands,
                                                        CowlAnnotationVec *annot) {
    CowlAxiomType axiom_type = (CowlAxiomType)type + CAT_SAME_INDIVIDUAL;
    return cowl_nary_individual_axiom_alloc(axiom_type, operands, annot);
}

CowlNAryIndividualAxiom* cowl_nary_individual_axiom_retain(CowlNAryIndividualAxiom *axiom) {
    return cowl_object_retain(axiom);
}

void cowl_nary_individual_axiom_release(CowlNAryIndividualAxiom *axiom) {
    if (axiom && !cowl_object_release(axiom)) {
        cowl_nary_individual_axiom_free(axiom);
    }
}

CowlNAryAxiomType cowl_nary_individual_axiom_get_type(CowlNAryIndividualAxiom *axiom) {
    CowlAxiomFlags flags = axiom->super.flags;
    return (CowlNAryAxiomType)(cowl_axiom_flags_get_type(flags) - CAT_SAME_INDIVIDUAL);
}

CowlIndividualSet* cowl_nary_individual_axiom_get_operands(CowlNAryIndividualAxiom *axiom) {
    return axiom->operands;
}

CowlAnnotationVec* cowl_nary_individual_axiom_get_annot(CowlNAryIndividualAxiom *axiom) {
    return cowl_axiom_get_annot(axiom);
}

bool cowl_nary_individual_axiom_equals(CowlNAryIndividualAxiom *lhs, CowlNAryIndividualAxiom *rhs) {
    return cowl_axiom_equals_impl(lhs, rhs,
                                  cowl_individual_set_equals(lhs->operands, rhs->operands));
}

cowl_uint_t cowl_nary_individual_axiom_hash(CowlNAryIndividualAxiom *axiom) {
    return cowl_object_hash_get(axiom);
}

bool cowl_nary_individual_axiom_iterate_signature(CowlNAryIndividualAxiom *axiom, void *ctx,
                                                  CowlEntityIterator iter) {
    if (!cowl_individual_set_iterate_signature(axiom->operands, ctx, iter)) return false;
    if (!cowl_axiom_annot_iterate_signature(axiom, ctx, iter)) return false;
    return true;
}
