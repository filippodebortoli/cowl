/// @author Ivano Bilenchi

#include "cowl_obj_card_private.h"
#include "cowl_obj_prop_exp.h"
#include "cowl_hash_utils.h"

#pragma mark - Private

static CowlObjCard* cowl_obj_card_alloc(CowlClsExpType type, CowlObjPropExp *prop,
                                        CowlClsExp *filler, uint32_t cardinality) {
    uint32_t hash = cowl_hash_4(COWL_HASH_INIT_OBJ_CARD,
                                type, cardinality,
                                cowl_obj_prop_exp_hash(prop),
                                cowl_cls_exp_hash(filler));

    CowlObjCard init = {
        .super = COWL_CLS_EXP_INIT(type, hash),
        .prop = cowl_obj_prop_exp_retain(prop),
        .filler = cowl_cls_exp_retain(filler),
        .cardinality = cardinality
    };

    struct CowlObjCard *restr = malloc(sizeof(*restr));
    memcpy(restr, &init, sizeof(*restr));
    return restr;
}

static void cowl_obj_card_free(CowlObjCard *restr) {
    if (!restr) return;
    cowl_obj_prop_exp_release(restr->prop);
    cowl_cls_exp_release(restr->filler);
    free((void *)restr);
}

#pragma mark - Public

CowlObjCard* cowl_obj_card_get(CowlObjCardType type, CowlObjPropExp *prop,
                               CowlClsExp *filler, uint32_t cardinality) {
    return cowl_obj_card_alloc(CCET_OBJ_MIN_CARD + type, prop, filler, cardinality);
}

CowlObjCard* cowl_obj_card_retain(CowlObjCard *restr) {
    return cowl_cls_exp_ref_incr(restr);
}

void cowl_obj_card_release(CowlObjCard *restr) {
    if (restr && !cowl_cls_exp_ref_decr(restr)) {
        cowl_obj_card_free(restr);
    }
}

CowlObjCardType cowl_obj_card_get_type(CowlObjCard *restr) {
    return restr->super.type - CCET_OBJ_MIN_CARD;
}

CowlObjPropExp* cowl_obj_card_get_prop(CowlObjCard *restr) {
    return restr->prop;
}

CowlClsExp* cowl_obj_card_get_filler(CowlObjCard *restr) {
    return restr->filler;
}

uint32_t cowl_obj_card_get_cardinality(CowlObjCard *restr) {
    return restr->cardinality;
}

bool cowl_obj_card_equals(CowlObjCard *lhs, CowlObjCard *rhs) {
    return lhs->cardinality == rhs->cardinality &&
           lhs->super.type == rhs->super.type &&
           cowl_obj_prop_exp_equals(lhs->prop, rhs->prop) &&
           cowl_cls_exp_equals(lhs->filler, rhs->filler);
}

uint32_t cowl_obj_card_hash(CowlObjCard *restr) {
    return cowl_cls_exp_hash_get(restr);
}

bool cowl_obj_card_iterate_signature(CowlObjCard *restr,
                                     void *ctx, CowlEntityIterator iter) {
    if (!cowl_obj_prop_exp_iterate_signature(restr->prop, ctx, iter)) return false;
    if (!cowl_cls_exp_iterate_signature(restr->filler, ctx, iter)) return false;
    return true;
}