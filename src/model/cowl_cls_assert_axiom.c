/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2020 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_cls_assert_axiom_private.h"
#include "cowl_cls_exp_private.h"
#include "cowl_individual_private.h"
#include "cowl_str_buf.h"

static CowlClsAssertAxiom* cowl_cls_assert_axiom_alloc(CowlIndividual *ind, CowlClsExp *exp,
                                                       CowlAnnotationVec *annot) {
    CowlClsAssertAxiom *axiom = cowl_axiom_alloc(axiom, annot);
    cowl_uint_t hash = cowl_axiom_hash_2(COWL_HASH_INIT_CLS_ASSERT_AXIOM, annot,
                                         cowl_individual_hash(ind),
                                         cowl_cls_exp_hash(exp));

    cowl_axiom_init(CowlClsAssertAxiom, axiom, annot,
        .super = COWL_AXIOM_INIT(COWL_AT_CLASS_ASSERT, hash, annot),
        .ind = cowl_individual_retain(ind),
        .cls_exp = cowl_cls_exp_retain(exp)
    );

    return axiom;
}

static void cowl_cls_assert_axiom_free(CowlClsAssertAxiom *axiom) {
    if (!axiom) return;
    cowl_individual_release(axiom->ind);
    cowl_cls_exp_release(axiom->cls_exp);
    cowl_axiom_free(axiom);
}

CowlClsAssertAxiom* cowl_cls_assert_axiom_get(CowlIndividual *ind, CowlClsExp *exp,
                                              CowlAnnotationVec *annot) {
    return cowl_cls_assert_axiom_alloc(ind, exp, annot);
}

CowlClsAssertAxiom* cowl_cls_assert_axiom_retain(CowlClsAssertAxiom *axiom) {
    return cowl_object_retain(axiom);
}

void cowl_cls_assert_axiom_release(CowlClsAssertAxiom *axiom) {
    if (axiom && !cowl_object_release(axiom)) {
        cowl_cls_assert_axiom_free(axiom);
    }
}

CowlIndividual* cowl_cls_assert_axiom_get_ind(CowlClsAssertAxiom *axiom) {
    return axiom->ind;
}

CowlClsExp* cowl_cls_assert_axiom_get_cls_exp(CowlClsAssertAxiom *axiom) {
    return axiom->cls_exp;
}

CowlAnnotationVec* cowl_cls_assert_axiom_get_annot(CowlClsAssertAxiom *axiom) {
    return cowl_axiom_get_annot(axiom);
}

CowlString* cowl_cls_assert_axiom_to_string(CowlClsAssertAxiom *axiom) {
    CowlStrBuf *buf = cowl_str_buf_alloc();
    cowl_str_buf_append_cls_assert(buf, axiom);
    return cowl_str_buf_to_string(buf);
}

bool cowl_cls_assert_axiom_equals(CowlClsAssertAxiom *lhs, CowlClsAssertAxiom *rhs) {
    return cowl_axiom_equals_impl(lhs, rhs,
                                  cowl_individual_equals(lhs->ind, rhs->ind) &&
                                  cowl_cls_exp_equals(lhs->cls_exp, rhs->cls_exp));
}

cowl_uint_t cowl_cls_assert_axiom_hash(CowlClsAssertAxiom *axiom) {
    return cowl_object_hash_get(axiom);
}

bool cowl_cls_assert_axiom_iterate_signature(CowlClsAssertAxiom *axiom, CowlEntityIterator *iter) {
    if (!cowl_individual_iterate_signature(axiom->ind, iter)) return false;
    if (!cowl_cls_exp_iterate_signature(axiom->cls_exp, iter)) return false;
    if (!cowl_axiom_annot_iterate_signature(axiom, iter)) return false;
    return true;
}

bool cowl_cls_assert_axiom_iterate_anon_inds(CowlClsAssertAxiom *axiom, CowlAnonIndIterator *iter) {
    if (!cowl_individual_iterate_anon_inds(axiom->ind, iter)) return false;
    if (!cowl_cls_exp_iterate_anon_inds(axiom->cls_exp, iter)) return false;
    if (!cowl_axiom_annot_iterate_anon_inds(axiom, iter)) return false;
    return true;
}
