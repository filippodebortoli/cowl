/**
 * Declares CowlIRI and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_IRI_H
#define COWL_IRI_H

#include "cowl_object.h"
#include "cowl_string.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlString);
cowl_struct_decl(CowlIRI);
/// @endcond

/**
 * Represents [International Resource Identifiers].
 *
 * [International Resource Identifiers]: https://www.w3.org/TR/owl2-syntax/#IRIs
 *
 * @struct CowlIRI
 * @extends CowlAnnotValue
 */

/**
 * Returns an IRI whose string representation is the concatenation of the specified strings.
 *
 * @param prefix The prefix.
 * @param suffix The suffix.
 * @return IRI, or NULL on error
 *
 * @public @memberof CowlIRI
 */
COWL_API
COWL_RETAINED
CowlIRI *cowl_iri(CowlString *prefix, CowlString *suffix);

/**
 * Returns an IRI given its string representation.
 *
 * @param string String representation of the IRI.
 * @return IRI, or NULL on error
 *
 * @public @memberof CowlIRI
 */
COWL_API
COWL_RETAINED
CowlIRI *cowl_iri_from_string(UString string);

/**
 * Returns an IRI given its static string representation.
 *
 * @param CSTR [char const[]] Static string.
 * @return [CowlIRI *] IRI, or NULL on error
 *
 * @public @related CowlIRI
 */
COWL_RETAINED
#define cowl_iri_from_static(CSTR) (cowl_iri_from_string(ustring_literal(CSTR)))

/**
 * Gets the namespace of the specified IRI.
 *
 * @param iri The IRI.
 * @return The namespace.
 *
 * @public @memberof CowlIRI
 */
COWL_API
COWL_PURE
CowlString *cowl_iri_get_ns(CowlIRI *iri);

/**
 * Gets the remainder of the specified IRI.
 *
 * @param iri The IRI.
 * @return The remainder.
 *
 * @public @memberof CowlIRI
 */
COWL_API
COWL_PURE
CowlString *cowl_iri_get_rem(CowlIRI *iri);

/**
 * Checks whether the IRI has a remainder.
 *
 * @param iri The IRI.
 * @return True if the IRI has a remainder, false otherwise.
 *
 * @public @memberof CowlIRI
 */
COWL_PURE
COWL_INLINE
bool cowl_iri_has_rem(CowlIRI *iri) {
    return cowl_string_get_length(cowl_iri_get_rem(iri)) > 0;
}

/**
 * Checks whether the IRI is in the reserved vocabulary.
 *
 * @param iri The IRI.
 * @return True if the IRI is reserved, false otherwise.
 *
 * @public @memberof CowlIRI
 */
COWL_API
COWL_PURE
bool cowl_iri_is_reserved(CowlIRI *iri);

COWL_END_DECLS

#endif // COWL_IRI_H
