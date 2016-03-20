<?php
/**
 * Created by PhpStorm.
 * User: Misumoo
 * Date: 3/19/2016
 * Time: 2:28 PM
 */

/**
 * Shared Interface for interactions
 */
interface Model {
  /**
   * Load a Model
   * @param int $address_id
   */

  static function load($address_id);

  /**
   * Save a model.
   */
  function save();
}