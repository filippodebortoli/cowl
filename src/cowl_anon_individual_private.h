/// @author Ivano Bilenchi

#ifndef COWL_ANON_INDIVIDUAL_PRIVATE_H
#define COWL_ANON_INDIVIDUAL_PRIVATE_H

#include "cowl_anon_individual.h"
#include "cowl_individual_private.h"

COWL_BEGIN_DECLS

typedef struct CowlAnonIndividual {
    CowlIndividual super;
    CowlString const *id;
} CowlAnonIndividual;

COWL_END_DECLS

#endif // COWL_ANON_INDIVIDUAL_PRIVATE_H
