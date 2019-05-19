#include "compare.h"
#include "ctest.h"
#include "mark.h"

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

CTEST(mark, over_100)
{
    ASSERT_EQUAL(0, Mark(100, 30));
}

CTEST(mark, below_0)
{
    ASSERT_EQUAL(0, Mark(-50, 50));
}

CTEST(mark_easy, 5_max)
{
    ASSERT_EQUAL(5, Mark(15, 5));
}

CTEST(mark_easy, 5_min)
{
    ASSERT_EQUAL(5, Mark(14, 5));
}

CTEST(mark_easy, 4_max)
{
    ASSERT_EQUAL(4, Mark(13, 5));
}

CTEST(mark_easy, 4_min)
{
    ASSERT_EQUAL(4, Mark(12, 5));
}

CTEST(mark_easy, 3_max)
{
    ASSERT_EQUAL(3, Mark(11, 5));
}

CTEST(mark_easy, 3_min)
{
    ASSERT_EQUAL(3, Mark(8, 5));
}

CTEST(mark_easy, 2_max)
{
    ASSERT_EQUAL(2, Mark(7, 5));
}

CTEST(mark_easy, 2_min)
{
    ASSERT_EQUAL(2, Mark(0, 5));
}