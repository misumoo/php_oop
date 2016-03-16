<?php

/*
 * Physical Address
 */
class Address {
  // Street address
  public $street_address_1;
  public $street_address_2;

  // City name
  public $city_name;

  // Name of subdivision
  public $subdivision_name;

  // Postal Code
  protected $_postal_code;

  // Name of the Country
  public $country_name;

  // Primary key of an Address
  protected $_address_id;

  // When the record was created and last updated.
  protected $_time_created;
  protected $_time_updated;

  /*
   * Magic __get.
   * @param string $name
   * @return mixed
   */
  function __get($name) {
    //postal code lookup if unset
    if(!$this->_postal_code) {
      $this->_postal_code = $this->_postal_code_guess();
    }

    // Attempt to return a protected property by name.
    $protected_porpert_name = '_' . $name;
    if(property_exists($this, $protected_porpert_name)) {
      return $this->$protected_porpert_name;
    }

    // Unable to access property; trigger error
    trigger_error('Undefined property via __get: ' . $name);
    return NULL;
  }

  /*
   * Magic __set
   * @param string $name
   * @param mixed $value
   */
  function __set($name, $value) {
    //allow anything to set the postal code
    if('postal_code' == $name) {
      $this->$name = $value;
      return;
    }

    //Unable to access property; trigger error
    trigger_error('Undefined or unallowed property via __set(): ' . $name);
  }

  /*
   *  Magic __toString
   *  @return string
   */
  function __toString()  {
    return $this->display();
  }

  /*
   * Constructor.
   * @param type $data Optional array of property names and value
   */
  function __construct($data = array()) {
    $this->_time_created = time();

    // Insure the address can be populated
    if(!is_array($data)) {
      trigger_error('Unable to construct address with a ' . get_class($name));
    }

    // If there is at least one value, populate the Address with it.
    if(count($data) > 0) {
      foreach($data as $name => $value) {
        //special case for protected properties
        if(in_array($name, array(
          'time_created',
          'time_updated',
        ))) {
          $name = '_' . $name;
        }
        $this->$name = $value;
      }
    }
  }

  /*
   * Guess the postal code based on subdivision and city name
   * @todo Replace with DB lookup
   * @return string
   */
  protected function _postal_code_guess() {
    return 'LOOKUP';
  }

  /*
   * Return HTML display for address.
   * @return string
   */
  function display() {
    $output = "";

    // Street address
    $output .= $this->street_address_1;
    if($this->street_address_2) {
      $output .= "<br />";
      $output .= $this->street_address_2;
    }

    // City, Subdivision Postal
    $output .= "<br />";
    $output .= $this->city_name . ', ' . $this->subdivision_name . ' ' . $this->postal_code;

    // Country
    $output .= "<br />";
    $output .= $this->country_name;

    return $output;
  }
}

?>