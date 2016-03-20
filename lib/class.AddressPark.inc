<?php
/**
 * Created by PhpStorm.
 * User: Misumoo
 * Date: 3/20/2016
 * Time: 1:02 AM
 */

/**
 * Park Address
 */
class AddressPark extends Address {

  public function display() {
    $output = '<div style="background-color: green;">';
    $output .= parent::display();
    $output .= '</div>';

    return $output;
  }
  /**
   * Initialization.
   */
  protected function _init() {
    $this->_setAddressTypeId(Address::ADDRESS_TYPE_PARK);
  }
}