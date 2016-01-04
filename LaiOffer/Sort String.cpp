//
//  Sort String.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 * Convert a string with the following rules:
 *
 * Assumption:
 * The input String will be always as form
 * "A1B2C3D4..."
 * The characters are sorted upper case letters in ['A', 'I'].
 * Each upper case letter character is followed by a character in ['1', '9'].
 * The mapping is 'A' -> '1', 'B' -> '2', 'C' -> '3', ..., 'I' -> '9'.
 *
 * Requirement:
 * Convert the input String to group all the upper case letters to
 * the left partition, and group all the digit characters to the right
 * partition, both partitions are sorted.
 *
 * Example:
 * "A1B2" -> "AB12"
 * "A1B2C3" -> "ABC123"
 */

#include <string>
#include <iostream>
using namespace std;


