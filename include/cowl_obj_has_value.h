/**
 * Declares CowlObjHasValue and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_OBJ_HAS_VALUE_H
#define COWL_OBJ_HAS_VALUE_H

#include "cowl_object.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlIndividual);
cowl_struct_decl(CowlObjPropExp);
cowl_struct_decl(CowlObjHasValue);
/// @endcond

/**
 * Represents [ObjectHasValue] in the OWL 2 specification.
 *
 * [ObjectHasValue]: https://www.w3.org/TR/owl2-syntax/#Individual_Value_Restriction
 *
 * @struct CowlObjHasValue
 * @extends CowlClsExp
 */

/**
 * Returns a retained individual value restriction.
 *
 * @param prop The object property expression.
 * @param individual The individual.
 * @return Retained restriction, or NULL on error.
 *
 * @public @memberof CowlObjHasValue
 */
COWL_INLINE
CowlObjHasValue *cowl_obj_has_value(CowlAnyObjPropExp *prop, CowlAnyIndividual *individual) {
    return (CowlObjHasValue *)cowl_get_impl_2(COWL_OT_CE_OBJ_HAS_VALUE, prop, individual);
}

/**
 * Gets the object property expression of the specified individual value restriction.
 *
 * @param exp The restriction.
 * @return The object property expression.
 *
 * @public @memberof CowlObjHasValue
 */
COWL_INLINE
CowlObjPropExp *cowl_obj_has_value_get_prop(CowlObjHasValue *exp) {
    return (CowlObjPropExp *)cowl_get_field(exp, 0);
}

/**
 * Gets the individual of the specified individual value restriction.
 *
 * @param exp The restriction.
 * @return The individual.
 *
 * @public @memberof CowlObjHasValue
 */
COWL_INLINE
CowlIndividual *cowl_obj_has_value_get_ind(CowlObjHasValue *exp) {
    return (CowlIndividual *)cowl_get_field(exp, 1);
}

/**
 * Returns the string representation of the specified value restriction.
 *
 * @param exp The restriction.
 * @return String representation, or NULL on error.
 *
 * @note The returned string is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlObjHasValue
 */
COWL_INLINE
CowlString *cowl_obj_has_value_to_string(CowlObjHasValue *exp) {
    return cowl_to_string(exp);
}

/**
 * Equality function.
 *
 * @param lhs LHS of the equality relation.
 * @param rhs RHS of the equality relation.
 * @return True if the equality relation holds, false otherwise.
 *
 * @public @memberof CowlObjHasValue
 */
COWL_INLINE
bool cowl_obj_has_value_equals(CowlObjHasValue *lhs, CowlObjHasValue *rhs) {
    return cowl_equals_impl(lhs, rhs);
}

/**
 * Hash function.
 *
 * @param exp The restriction.
 * @return The hash value.
 *
 * @public @memberof CowlObjHasValue
 */
COWL_INLINE
ulib_uint cowl_obj_has_value_hash(CowlObjHasValue *exp) {
    return cowl_hash_impl(exp);
}

COWL_END_DECLS

#endif // COWL_OBJ_HAS_VALUE_H
