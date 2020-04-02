/**
 * Declares CowlObjHasSelf and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_OBJ_HAS_SELF_H
#define COWL_OBJ_HAS_SELF_H

#include "cowl_std.h"
#include "cowl_iterator.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlObjPropExp);
cowl_struct_decl(CowlObjHasSelf);
/// @endcond

/**
 * Represents [ObjectHasSelf] in the OWL 2 specification.
 *
 * [ObjectHasSelf]: https://www.w3.org/TR/owl2-syntax/#Self-Restriction
 *
 * @struct CowlObjHasSelf
 * @extends CowlClsExp
 */

/**
 * Returns a retained self-restriction.
 *
 * @param prop The property expression.
 * @return Retained restriction.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_PUBLIC
CowlObjHasSelf* cowl_obj_has_self_get(CowlObjPropExp *prop);

/**
 * Retains the specified self-restriction.
 *
 * @param exp The restriction.
 * @return Retained restriction.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_PUBLIC
CowlObjHasSelf* cowl_obj_has_self_retain(CowlObjHasSelf *exp);

/**
 * Releases the specified self-restriction.
 *
 * @param exp The restriction.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_PUBLIC
void cowl_obj_has_self_release(CowlObjHasSelf *exp);

/**
 * Gets the object property expression of the specified self-restriction.
 *
 * @param exp The restriction.
 * @return The object property expression.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_PUBLIC
CowlObjPropExp* cowl_obj_has_self_get_prop(CowlObjHasSelf *exp);

/**
 * Returns the string representation of the specified self-restriction.
 *
 * @param exp The restriction.
 * @return String representation.
 *
 * @note The returned string is retained, so you are responsible for releasing it.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_PUBLIC
CowlString* cowl_obj_has_self_to_string(CowlObjHasSelf *exp);

/**
 * Equality function.
 *
 * @param lhs LHS of the equality relation.
 * @param rhs RHS of the equality relation.
 * @return True if the equality relation holds, false otherwise.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_PUBLIC
bool cowl_obj_has_self_equals(CowlObjHasSelf *lhs, CowlObjHasSelf *rhs);

/**
 * Hash function.
 *
 * @param exp The restriction.
 * @return The hash value.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_PUBLIC
cowl_uint_t cowl_obj_has_self_hash(CowlObjHasSelf *exp);

/**
 * Iterates over the signature of the specified self-restriction.
 *
 * @param exp The restriction.
 * @param iter The entity iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_PUBLIC
bool cowl_obj_has_self_iterate_signature(CowlObjHasSelf *exp, CowlEntityIterator *iter);

/**
 * Iterates over the primitives referenced by the specified self-restriction.
 *
 * @param exp The restriction.
 * @param iter The primitive iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlObjHasSelf
 */
COWL_PUBLIC
bool cowl_obj_has_self_iterate_primitives(CowlObjHasSelf *exp, CowlPrimitiveIterator *iter);

COWL_END_DECLS

#endif // COWL_OBJ_HAS_SELF_H
