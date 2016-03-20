<?php
/**
 * Created by PhpStorm.
 * User: Misumoo
 * Date: 3/20/2016
 * Time: 1:01 AM
 */

/**
 * Residential Address
 */
class AddressResidence extends Address {
  /**
   * Initialization.
   */
  protected function _init() {
    $this->_setAddressTypeId(Address::ADDRESS_TYPE_RESIDENCE);
  }
}