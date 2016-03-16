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

require("lib/class.Address.inc");

echo "<h2>Instantiating Address</h2>";
$address = new Address();

echo "<h2>Empty Address</h2>";
echo "<pre>" . var_export($address, true) . "</pre>";

echo "<h2>Setting Properties</h2>";
$address->street_address_1 = '555 Fake Street';
$address->city_name = 'Townsville';
$address->subdivision_name = 'State';
$address->postal_code = '12345';
$address->country_name = 'United States of America';
echo "<pre>" . var_export($address, true) . "</pre>";

echo "<h2>Display Address</h2>";
echo $address->display();

echo "<h2>Testing Magic __get and __set</h2>";
unset($address->postal_code);
echo $address->display();

echo "<h2>Testing __construct with an array</h2>";
$address2 = new Address(array(
  'street_address_1' => '123 Phony Avenue',
  'city_name' => 'VillageLand',
  'subdivision_name' => 'Region',
  'postal_code' => '67980',
  'country_name' => 'Canada'
));
echo $address2->display();

echo "<h2>Address __toString</h2>";
echo $address2;