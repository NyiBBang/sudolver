#include "config.h"
#include "logic/Validator.h"

namespace
{
const grid_value_type invalidGrid =
    {{1, 2, 3, 4, 5, 6, 7, 8, 9,
      1, 2, 3, 4, 5, 6, 7, 8, 9,
      1, 2, 3, 4, 5, 6, 7, 8, 9,
      1, 2, 3, 4, 5, 6, 7, 8, 9,
      1, 2, 3, 4, 5, 6, 7, 8, 9,
      1, 2, 3, 4, 5, 6, 7, 8, 9,
      1, 2, 3, 4, 5, 6, 7, 8, 9,
      1, 2, 3, 4, 5, 6, 7, 8, 9,
      1, 2, 3, 4, 5, 6, 7, 8, 9}};

const grid_value_type validGrid =
    {{1, 2, 3, 4, 5, 6, 7, 8, 9,
      4, 5, 6, 7, 8, 9, 1, 2, 3,
      7, 8, 9, 1, 2, 3, 4, 5, 6,
      2, 3, 4, 5, 6, 7, 8, 9, 1,
      5, 6, 7, 8, 9, 1, 2, 3, 4,
      8, 9, 1, 2, 3, 4, 5, 6, 7,
      3, 4, 5, 6, 7, 8, 9, 1, 2,
      6, 7, 8, 9, 1, 2, 3, 4, 5,
      9, 1, 2, 3, 4, 5, 6, 7, 8}};
}

const grid_value_type notFullGrid =
    {{0, 0, 2, 0, 5, 6, 0, 0, 7,
      6, 0, 0, 9, 8, 0, 0, 0, 0,
      8, 0, 0, 1, 3, 0, 9, 0, 4,
      0, 3, 0, 0, 0, 0, 8, 0, 0,
      4, 5, 0, 2, 7, 8, 0, 3, 1,
      0, 0, 8, 0, 0, 0, 0, 2, 0,
      5, 0, 3, 0, 9, 4, 0, 0, 6,
      0, 0, 0, 0, 1, 3, 0, 0, 8,
      9, 0, 0, 7, 2, 0, 4, 0, 0}};

BOOST_AUTO_TEST_CASE(validator_does_not_validate_an_empty_grid)
{
    grid_entity_type grid(new grid_value_type);
    Validator validator(grid);
    BOOST_CHECK(!validator.isValid());
}

BOOST_AUTO_TEST_CASE(validator_does_not_validate_an_invalid_grid)
{
    grid_entity_type grid(new grid_value_type(invalidGrid));
    Validator validator(grid);
    BOOST_CHECK(!validator.isValid());
}

BOOST_AUTO_TEST_CASE(validator_validates_a_valid_grid)
{
    grid_entity_type grid(new grid_value_type(validGrid));
    Validator validator(grid);
    BOOST_CHECK(validator.isValid());
}

BOOST_AUTO_TEST_CASE(validator_checks_that_grid_is_not_fully_defined)
{
    grid_entity_type grid(new grid_value_type(notFullGrid));
    Validator validator(grid);
    BOOST_CHECK(!validator.isFullyDefined());
}

BOOST_AUTO_TEST_CASE(validator_checks_that_valid_grid_is_fully_defined)
{
    grid_entity_type grid(new grid_value_type(validGrid));
    Validator validator(grid);
    BOOST_CHECK(validator.isFullyDefined());
}

BOOST_AUTO_TEST_CASE(validator_checks_that_even_invalid_grid_is_fully_defined)
{
    grid_entity_type grid(new grid_value_type(invalidGrid));
    Validator validator(grid);
    BOOST_CHECK(validator.isFullyDefined());
}

