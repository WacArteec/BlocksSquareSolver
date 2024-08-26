#ifndef TESTS_H
#define TESTS_H
#include "Structures.h"

struct CheckNumbers /**< keep right coefficients and solutions of equation for tests */
{
    Parameters par_a; /**< coefficients of equation */
    Solution sol_a; /**< solutions and their count */
};

void Checker();

#endif // TESTS_H
