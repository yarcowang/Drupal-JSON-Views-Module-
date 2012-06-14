<?php
/**
 * @file
 * Views hooks for views_json_backend.
 */

/**
 * Implements hook_views_data().
 */
function views_json_backend_views_data() {
  $data = array();
  $data['json']['table']['group'] = t('Json');

  $data['json']['table']['base'] = array(
    'title' => t('Json'),
    'help' => t('Queries an Json file.'),
    'query class' => 'views_json_backend',
  );

  $data['json']['value'] = array(
    'title' => t('value'),
    'help' => t('value in the Json file.'),
    'field' => array(
      'handler' => 'views_json_backend_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_json_backend_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_json_backend_handler_sort',
    ),
    //'argument' => array(
    //  'handler' => 'views_xml_backend_handler_argument',
    //),
  );

	/*
  $data['json']['date'] = array(
    'title' => t('Date'),
    'help' => t('Date in the XML file.'),
    'field' => array(
      'handler' => 'views_xml_backend_handler_field_date',
      'click sortable' => FALSE,
    ),
    //'argument' => array(
    //  'handler' => 'views_xml_backend_handler_argument',
    //),
  );

  $data['xml']['numeric'] = array(
    'title' => t('Numeric'),
    'help' => t('A number in the XML file.'),
    //'field' => array(
    //  'handler' => 'views_xml_backend_handler_field',
    //),
    'filter' => array(
      'handler' => 'views_xml_backend_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_xml_backend_handler_sort_numeric',
    ),
    //'argument' => array(
    //  'handler' => 'views_xml_backend_handler_argument',
    //),
  );
	*/

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function views_json_backend_views_plugins() {
  return array(
    'query' => array(
      'views_json_backend' => array(
        'title' => t('Json'),
        'help' => t('Reads from an Json file.'),
        'handler' => 'views_json_backend_plugin_query_json',
      ),
    ),
  );
}
