<?php
/**
 * @file
 * Adminstration settings for the Islandora MARCXML module.
 */

/**
 * Adminstration form for the Islandora MARCXML module.
 */
function islandora_marcxml_admin_settings(array $form, array &$form_state) {
  $form['islandora_marcxml_allow_editing_of_existing_mods'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow user to upload a new copy of the MARCXML to be re-transformed and stored as MODS.'),
    '#description' => t("This provides an extra option to be available under the 'edit' link present on objects that have MODS datastreams."),
    '#default_value' => variable_get('islandora_marcxml_allow_editing_of_existing_mods', FALSE),
  );
  $form['islandora_marcxml_select_marc_to_mods_xsl'] = array(
    '#type' => 'select',
    '#title' => t('MARC to MODS XSL file'),
    '#default_value' => variable_get('islandora_marcxml_select_marc_to_mods_xsl', 'MARC21slim2MODS3-6.xsl'),
    '#options' => array(
      'MARC21slim2MODS3-5.xsl' => t('MARCXML to MODS 3.5'),
      'MARC21slim2MODS3-6.xsl' => t('MARCXML to MODS 3.6'),
    ),
    '#description' => t('Select the MARC to MODS XSL file to convert your uploaded MARCXML to MODS.'),
  );
  $form['islandora_marcxml_select_mods_to_marc_xsl'] = array(
    '#type' => 'select',
    '#title' => t('MODS to MARC XSL file'),
    '#default_value' => variable_get('islandora_marcxml_select_mods_to_marc_xsl', 'MODS3-4_MARC21slim_XSLT1-0.xsl'),
    '#options' => array(
      'MODS2MARC21slim.xsl' => t('MODS 3.0 to MARCXML'),
      'MODS3-4_MARC21slim_XSLT1-0.xsl' => t('MODS 3.4 to MARC XSLT 1.0'),
    ),
    '#description' => t('Select the MARC to MODS XSL file to convert your uploaded MARCXML to MODS.'),
  );
  return system_settings_form($form);
}
