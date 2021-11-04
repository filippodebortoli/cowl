/**
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019-2020 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://swot.sisinflab.poliba.it>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#include "cowl_api.h"
#include "cowl_iri_tests.h"
#include "cowl_ontology_tests.h"
#include "cowl_reader_tests.h"
#include "cowl_string_tests.h"
#include "cowl_version_tests.h"

utest_main(
    cowl_api_init();
    utest_run("string", COWL_STRING_TESTS);
    utest_run("iri", COWL_IRI_TESTS);
    utest_run("reader", COWL_READER_TESTS);
    utest_run("ontology", COWL_ONTOLOGY_TESTS);
    utest_run("version", COWL_VERSION_TESTS);
    cowl_api_deinit();
)
