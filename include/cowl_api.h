/**
 * Umbrella header for the Cowl API.
 *
 * @author Ivano Bilenchi
 *
 * @copyright Copyright (c) 2019 SisInf Lab, Polytechnic University of Bari
 * @copyright <http://sisinflab.poliba.it/swottools>
 * @copyright SPDX-License-Identifier: EPL-2.0
 *
 * @file
 */

#ifndef COWL_API_H
#define COWL_API_H

#include "cowl_alloc.h"
#include "cowl_annot_assert_axiom.h"
#include "cowl_annot_prop.h"
#include "cowl_annot_prop_domain_axiom.h"
#include "cowl_annot_prop_range_axiom.h"
#include "cowl_annot_value.h"
#include "cowl_annot_value_type.h"
#include "cowl_annotation.h"
#include "cowl_annotation_vec.h"
#include "cowl_anon_ind.h"
#include "cowl_axiom.h"
#include "cowl_axiom_type.h"
#include "cowl_base_types.h"
#include "cowl_card_type.h"
#include "cowl_class.h"
#include "cowl_cls_assert_axiom.h"
#include "cowl_cls_exp.h"
#include "cowl_cls_exp_set.h"
#include "cowl_cls_exp_type.h"
#include "cowl_compat.h"
#include "cowl_data_card.h"
#include "cowl_data_compl.h"
#include "cowl_data_has_value.h"
#include "cowl_data_one_of.h"
#include "cowl_data_prop.h"
#include "cowl_data_prop_assert_axiom.h"
#include "cowl_data_prop_domain_axiom.h"
#include "cowl_data_prop_exp.h"
#include "cowl_data_prop_exp_set.h"
#include "cowl_data_prop_range_axiom.h"
#include "cowl_data_quant.h"
#include "cowl_data_range.h"
#include "cowl_data_range_set.h"
#include "cowl_data_range_type.h"
#include "cowl_datatype.h"
#include "cowl_datatype_def_axiom.h"
#include "cowl_datatype_restr.h"
#include "cowl_decl_axiom.h"
#include "cowl_disj_union_axiom.h"
#include "cowl_entity.h"
#include "cowl_entity_type.h"
#include "cowl_error.h"
#include "cowl_facet.h"
#include "cowl_facet_restr.h"
#include "cowl_facet_restr_set.h"
#include "cowl_flags.h"
#include "cowl_func_data_prop_axiom.h"
#include "cowl_has_key_axiom.h"
#include "cowl_imports_loader.h"
#include "cowl_individual.h"
#include "cowl_individual_set.h"
#include "cowl_inv_obj_prop.h"
#include "cowl_inv_obj_prop_axiom.h"
#include "cowl_iri.h"
#include "cowl_iterator.h"
#include "cowl_literal.h"
#include "cowl_literal_set.h"
#include "cowl_logger.h"
#include "cowl_named_ind.h"
#include "cowl_nary_axiom_type.h"
#include "cowl_nary_bool.h"
#include "cowl_nary_cls_axiom.h"
#include "cowl_nary_data.h"
#include "cowl_nary_data_prop_axiom.h"
#include "cowl_nary_ind_axiom.h"
#include "cowl_nary_obj_prop_axiom.h"
#include "cowl_nary_type.h"
#include "cowl_node_id.h"
#include "cowl_obj_card.h"
#include "cowl_obj_compl.h"
#include "cowl_obj_has_self.h"
#include "cowl_obj_has_value.h"
#include "cowl_obj_one_of.h"
#include "cowl_obj_prop.h"
#include "cowl_obj_prop_assert_axiom.h"
#include "cowl_obj_prop_char_axiom.h"
#include "cowl_char_axiom_type.h"
#include "cowl_obj_prop_domain_axiom.h"
#include "cowl_obj_prop_exp.h"
#include "cowl_obj_prop_exp_set.h"
#include "cowl_obj_prop_exp_vec.h"
#include "cowl_obj_prop_range_axiom.h"
#include "cowl_obj_quant.h"
#include "cowl_ontology.h"
#include "cowl_ontology_id.h"
#include "cowl_owl_vocab.h"
#include "cowl_parser.h"
#include "cowl_quant_type.h"
#include "cowl_rdf_vocab.h"
#include "cowl_rdfs_vocab.h"
#include "cowl_std.h"
#include "cowl_string.h"
#include "cowl_sub_annot_prop_axiom.h"
#include "cowl_sub_cls_axiom.h"
#include "cowl_sub_data_prop_axiom.h"
#include "cowl_sub_obj_prop_axiom.h"
#include "cowl_sub_obj_prop_chain_axiom.h"
#include "cowl_xsd_vocab.h"

COWL_BEGIN_DECLS

/**
 * Initializes the API.
 *
 * @note It's mandatory to call this function before making any other Cowl API call.
 */
COWL_PUBLIC
void cowl_api_init(void);

/**
 * Deinitializes the API.
 *
 * @note Calling this function releases any resource loaded when the API was initialized.
 *       You **must not** make API calls on objects retrieved before deinitializing the API, even
 *       if you later re-initialize it.
 */
COWL_PUBLIC
void cowl_api_deinit(void);

COWL_END_DECLS

#endif // COWL_API_H
