/**
 * Declares CowlNamedInd and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_NAMED_IND_H
#define COWL_NAMED_IND_H

#include "cowl_entity.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlNamedInd);
/// @endcond

/**
 * Represents a [NamedIndividual] in the OWL 2 specification.
 *
 * [NamedIndividual]: https://www.w3.org/TR/owl2-syntax/#Named_Individuals
 *
 * @struct CowlNamedInd
 * @extends CowlIndividual
 * @extends CowlEntity
 */

/**
 * Returns a named individual.
 *
 * @param iri IRI of the individual.
 * @return Named individual, or NULL on error.
 *
 * @public @memberof CowlNamedInd
 */
COWL_RETAINED
COWL_INLINE
CowlNamedInd *cowl_named_ind(CowlIRI *iri) {
    return (CowlNamedInd *)cowl_entity_get_impl(COWL_OT_I_NAMED, iri);
}

/**
 * Returns a named individual given the string representation of its IRI.
 *
 * @param string String representation of the IRI.
 * @return Named individual, or NULL on error.
 *
 * @public @memberof CowlNamedInd
 */
COWL_RETAINED
COWL_INLINE
CowlNamedInd *cowl_named_ind_from_string(UString string) {
    return (CowlNamedInd *)cowl_entity_from_string_impl(COWL_OT_I_NAMED, string);
}

/**
 * Returns a named individual given the static string representation of its IRI.
 *
 * @param CSTR [char const[]] Static string.
 * @return [CowlNamedInd *] Named individual, or NULL on error.
 *
 * @public @related CowlNamedInd
 */
COWL_RETAINED
#define cowl_named_ind_from_static(CSTR) cowl_named_ind_from_string(ustring_literal(CSTR))

/**
 * Gets the IRI of the named individual.
 *
 * @param ind The named individual.
 * @return IRI of the named individual.
 *
 * @public @memberof CowlNamedInd
 */
COWL_PURE
COWL_INLINE
CowlIRI *cowl_named_ind_get_iri(CowlNamedInd *ind) {
    return cowl_entity_get_iri((CowlEntity *)ind);
}

COWL_END_DECLS

#endif // COWL_NAMED_IND_H
