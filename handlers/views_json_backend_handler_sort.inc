<?php
/**
 * @file
 * Base sort handler for views_json_backend.
 */

class views_json_backend_handler_sort extends views_handler_sort {
  function option_definition() {
    $options = parent::option_definition();
    $options['key'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['key'] = array(
      '#title' => t('Key Chooser'),
      '#description' => t('choose a key'),
      '#type' => 'textfield',
      '#default_value' => $this->options['key'],
      '#required' => TRUE,
    );
  }

  /**
   * Called to add the sort to a query.
   */
  function query() {
    $this->query->add_orderby($this);
  }

  function sort(&$result) {
    $this->field = $this->options['key'];
    if (strtolower($this->options['order']) == 'asc') {
      usort($result, array($this, 'sort_asc'));
    }
    else {
      usort($result, array($this, 'sort_desc'));
    }
  }

  function sort_asc($a, $b) {
    $a_value = isset($a->{$this->field}) ? $a->{$this->field} : '';
    $b_value = isset($b->{$this->field}) ? $b->{$this->field} : '';
    return strcasecmp($a_value, $b_value);
  }

  function sort_desc($a, $b) {
    $a_value = isset($a->{$this->field}) ? $a->{$this->field} : '';
    $b_value = isset($b->{$this->field}) ? $b->{$this->field} : '';
    return -strcasecmp($a_value, $b_value);
  }

  function ui_name($short = FALSE) {
    if (!empty($this->options['ui_name'])) {
      $title = check_plain($this->options['ui_name']);
      return $title;
    }
    $title = ($short && isset($this->definition['title short'])) ? $this->definition['title short'] : $this->definition['title'];
    return t('!key: !title', array('!key' => $this->options['key'], '!title' => $title));
  }
}
