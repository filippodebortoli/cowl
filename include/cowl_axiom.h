/**
 * Declares CowlAxiom and its API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_AXIOM_H
#define COWL_AXIOM_H

#include "cowl_axiom_type.h"
#include "cowl_object.h"
#include "cowl_position.h"

COWL_BEGIN_DECLS

/// @cond
cowl_struct_decl(CowlVector);
cowl_struct_decl(CowlAxiom);
/// @endcond

/**
 * Represents an [Axiom] in the OWL 2 specification.
 *
 * [Axiom]: https://www.w3.org/TR/owl2-syntax/#Axioms
 *
 * @struct CowlAxiom
 * @extends CowlObject
 */

/**
 * Gets the type of the specified axiom.
 *
 * @param axiom The axiom.
 * @return Axiom type.
 *
 * @public @memberof CowlAxiom
 */
COWL_INLINE
CowlAxiomType cowl_axiom_get_type(CowlAnyAxiom *axiom) {
    return (CowlAxiomType)(cowl_get_type(axiom) - COWL_OT_A_DECL);
}

/**
 * Gets the annotations of the specified axiom.
 *
 * @param axiom The axiom.
 * @return The annotations.
 *
 * @public @memberof CowlAxiom
 */
COWL_INLINE
CowlVector *cowl_axiom_get_annot(CowlAnyAxiom *axiom) {
    return (CowlVector *)cowl_get_opt_field(axiom);
}

/**
 * Checks if the axiom has the specified operand.
 *
 * @param axiom The axiom.
 * @param operand The operand.
 * @param position Position where the operand should appear.
 * @return True if the axiom has the specified operand, false otherwise.
 *
 * @public @memberof CowlAxiom
 */
COWL_API
bool cowl_axiom_has_operand(CowlAnyAxiom *axiom, CowlAny *operand, CowlPosition position);

/**
 * Iterates over the operands of the specified axiom.
 *
 * @param axiom The axiom.
 * @param position Position of the desired operands.
 * @param iter The iterator.
 * @return True if the iteration was completed, false if it was stopped.
 *
 * @public @memberof CowlAxiom
 */
COWL_API
bool cowl_axiom_iterate_operands(CowlAnyAxiom *axiom, CowlPosition position, CowlIterator *iter);

COWL_END_DECLS

#endif // COWL_AXIOM_H
