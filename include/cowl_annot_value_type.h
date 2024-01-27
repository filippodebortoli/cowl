/**
 * Defines the CowlAnnotValueType enumeration.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_ANNOT_VALUE_TYPE_H
#define COWL_ANNOT_VALUE_TYPE_H

#include "cowl_attrs.h"

COWL_BEGIN_DECLS

/// Represents the type of @type{#CowlAnnotValue}.
typedef enum CowlAnnotValueType {

    /// @name Types

    /// @type{#CowlIRI} - IRI.
    COWL_AVT_IRI,

    /// @type{#CowlLiteral} - Literal.
    COWL_AVT_LITERAL,

    /// @type{#CowlAnonInd} - Anonymous individual.
    COWL_AVT_ANON_IND,

    /// @name Markers

    /// Number of enum values.
    COWL_AVT_COUNT,

    /// First enum value.
    COWL_AVT_FIRST = 0

} CowlAnnotValueType;

COWL_END_DECLS

#endif // COWL_ANNOT_VALUE_TYPE_H
