/// @author Ivano Bilenchi

#ifndef COWL_OBJ_ALL_PRIVATE_H
#define COWL_OBJ_ALL_PRIVATE_H

#include "cowl_obj_all.h"
#include "cowl_cls_exp_private.h"

COWL_BEGIN_DECLS

typedef struct CowlObjAll {
    CowlClsExp super;
    CowlObjPropExp const *prop;
    CowlClsExp const *filler;
} CowlObjAll;

COWL_END_DECLS

#endif // COWL_OBJ_ALL_PRIVATE_H
