/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2021 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_PARSER_CTX_PRIVATE_H
#define COWL_PARSER_CTX_PRIVATE_H

#include "cowl_parser_ctx.h"
#include "cowl_parser_private.h"

COWL_BEGIN_DECLS

cowl_struct_decl(CowlInputStream);
cowl_struct_decl(CowlOntology);
cowl_struct_decl(CowlSubParser);

typedef cowl_struct(CowlParserCtx) {
    CowlParser super;
} CowlParserCtx;

COWL_END_DECLS

#endif // COWL_PARSER_CTX_PRIVATE_H
