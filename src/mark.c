#include "mark.h"
#include <stdio.h>
#include <stdlib.h>

int Mark(float p, int k)
{
    float p1 = p;
    float m;
    m = (p1 / (k * 3)) * 100;
    if (m <= 100 && m >= 90) {
        return 5;
    }
    if (m < 90 && m >= 80) {
        return 4;
    }
    if (m < 80 && m >= 50) {
        return 3;
    }
    if (m < 50 && m >= 0) {
        return 2;
    } else {
        return 0;
    }
}