/// @author Ivano Bilenchi

#ifndef COWL_NARY_CLS_AXIOM_H
#define COWL_NARY_CLS_AXIOM_H

#include "cowl_iterator.h"
#include "cowl_std.h"
#include "khash_utils.h"

COWL_BEGIN_DECLS

typedef khash_struct(CowlClsExpSet) const CowlClsExpSet;

typedef struct CowlNAryClsAxiom const CowlNAryClsAxiom;

typedef enum CowlNAryClsAxiomType {
    CNCAT_EQUIVALENT_CLASSES,
    CNCAT_DISJOINT_CLASSES
} CowlNAryClsAxiomType;

CowlNAryClsAxiom* cowl_nary_cls_axiom_get(CowlNAryClsAxiomType type, CowlClsExpSet *classes);
CowlNAryClsAxiom* cowl_nary_cls_axiom_retain(CowlNAryClsAxiom *axiom);
void cowl_nary_cls_axiom_release(CowlNAryClsAxiom *axiom);

CowlNAryClsAxiomType cowl_nary_cls_axiom_get_type(CowlNAryClsAxiom *axiom);
CowlClsExpSet* cowl_nary_cls_axiom_get_classes(CowlNAryClsAxiom *axiom);

bool cowl_nary_cls_axiom_equals(CowlNAryClsAxiom *lhs, CowlNAryClsAxiom *rhs);
uint32_t cowl_nary_cls_axiom_hash(CowlNAryClsAxiom *axiom);

bool cowl_nary_cls_axiom_iterate_signature(CowlNAryClsAxiom *axiom,
                                           void *ctx, CowlEntityIterator iter);

COWL_END_DECLS

#endif // COWL_NARY_CLS_AXIOM_H