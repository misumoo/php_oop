<?php
/**
 * Created by PhpStorm.
 * User: Misumoo
 * Date: 3/14/2016
 * Time: 7:57 PM
 *
 * Object programming with Lynda.com
 * http://www.lynda.com/PHP-tutorials/Welcome/107953/113287-4.html
 *
 */

//require 'lib/class.Address.inc';
//require 'lib/class.Database.inc';

/**
 * Define autoloader.
 * @param $class_name
 */
function __autoload($class_name) {
  require 'lib/class.' . $class_name . '.inc';
}

echo "<h2>Instantiating AddressResidence</h2>";
$address_residence = new AddressResidence();

echo "<h2>Setting Properties</h2>";
$address_residence->street_address_1 = '555 Fake Street';
$address_residence->city_name = 'Townsville';
$address_residence->subdivision_name = 'State';
$address_residence->country_name = 'United States of America';
echo $address_residence;
echo '<pre>' . var_export($address_residence, TRUE) . '</pre>';

echo "<h2>Testing __construct with an array</h2>";
$address_business = new AddressBusiness(array(
  'street_address_1' => '123 Phony Avenue',
  'city_name' => 'VillageLand',
  'subdivision_name' => 'Region',
  'country_name' => 'Canada'
));
echo "<pre>" . var_export($address_business, TRUE) . "</pre>";

echo "<h2>Instantiating AddressPark</h2>";
$address_park = new AddressPark(array(
  'street_address_1' => '789 Missing Circle',
  'street_address_2' => 'Suite 0',
  'city_name' => 'Hamlet',
  'subdivision_name' => 'Territory',
  'country_name' => 'Australia',
));
echo $address_park;
echo "<pre>" . var_export($address_park, TRUE) . "</pre>";