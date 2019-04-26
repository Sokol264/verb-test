#include "compare.h"
#include "ctest.h"

CTEST(comparison_right, no_register_p)
{
    ASSERT_EQUAL(1, CompareR("swim", "swim"));
}

CTEST(comparison_right, no_register_m)
{
    ASSERT_EQUAL(0, CompareR("swam", "swim"));
}

CTEST(comparison_wrong, no_register_m)
{
    ASSERT_EQUAL(0, CompareW("swim", "swim"));
}

CTEST(comparison_wrong, no_register_p)
{
    ASSERT_EQUAL(1, CompareW("swam", "swim"));
}

CTEST(comparison_right, register_p)
{
    ASSERT_EQUAL(0, CompareR("Swim", "swim"));
}

CTEST(comparison_right, register_m)
{
    ASSERT_EQUAL(0, CompareR("Swam", "swim"));
}

CTEST(comparison_wrong, register_p)
{
    ASSERT_EQUAL(1, CompareW("Swam", "swim"));
}

CTEST(comparison_wrong, register_m)
{
    ASSERT_EQUAL(1, CompareW("Swim", "swim"));
}
