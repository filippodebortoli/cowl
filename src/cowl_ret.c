/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2020 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_ret_private.h"
#include "cowl_string_private.h"

char const* cowl_ret_to_cstring(cowl_ret ret) {
    switch (ret) {
        case COWL_OK: return "success";
        case COWL_ERR_IO: return "input/output error";
        case COWL_ERR_MEM: return "memory exhausted";
        case COWL_ERR_SYNTAX: return "syntax error";
        case COWL_ERR_IMPORT: return "import error";
        default: return "unknown error";
    }
}

CowlString* cowl_ret_to_string(cowl_ret ret) {
    return cowl_string_alloc(cowl_ret_to_raw_string(ret));
}

CowlRawString cowl_ret_to_raw_string(cowl_ret ret) {
    char const *cstring = cowl_ret_to_cstring(ret);
    return cowl_raw_string_init(cstring, strlen(cstring), true);
}
