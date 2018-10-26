/// @author Ivano Bilenchi

#ifndef COWL_OBJ_PROP_DOMAIN_AXIOM_PRIVATE_H
#define COWL_OBJ_PROP_DOMAIN_AXIOM_PRIVATE_H

#include "cowl_obj_prop_domain_axiom.h"
#include "cowl_axiom_private.h"

COWL_BEGIN_DECLS

struct CowlObjPropDomainAxiom {
    CowlAxiom super;
    CowlObjPropExp *prop_exp;
    CowlClsExp *domain;
};

COWL_END_DECLS

#endif // COWL_OBJ_PROP_DOMAIN_AXIOM_PRIVATE_H