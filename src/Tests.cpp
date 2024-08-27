/*! \file */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "MathForSolve.h"
#include "Tests.h"

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLACK   "\033[30m"      /* Black */

/** \brief UNIT test for this program
 *
 * \return void
 *
 */
 void Checker() /**<  */
{
    const CheckNumbers CheckMassive[] = {  /**< array of coefficients, right solves and their count for each equation */
    //a, b, c,  num roots, x1, x2
    {{0, 0, 0}, {Infinity, 0, 0}},
    {{0, 0, 1}, {Zero, 0, 0}},
    {{0, 1, 1}, {One, -1, 0}},
    {{1, 1, 1}, {Zero, 0, 0}},
    {{1, 2, 1}, {One, -1, 0}},
    {{2, 4, -6}, {Two, -3, 1}},
    {{7, 9, -13},{Two, -2.14964, 0.86393}},
    {{23, 23, -17},{Two, -1.49455, 0.49455}},
    {{0, 23, 17},{One, -0.73913, 0}},
    {{0, 1, 0},{One, 0, 0}}
    };
    const size_t sizeCheck = sizeof(CheckMassive)/sizeof(CheckMassive[0]);

    for(int i = 0; i < sizeCheck; i++)
    {
        assert (0 <= i && i < sizeCheck);

        struct Parameters par = {CheckMassive[i].par_a.a, CheckMassive[i].par_a.b, CheckMassive[i].par_a.c};
        struct Solution sol = {0, 0, 0};
        if(SolveManager(par, &sol)) LinearEquation(par.b, par.c, &sol);
        else SquareEquation(par.a, par.b, par.c, &sol);

        if(sol.countroots != CheckMassive[i].sol_a.countroots ||
           CompareFloats(sol.root1, CheckMassive[i].sol_a.root1) == 0 ||
           CompareFloats(sol.root2, CheckMassive[i].sol_a.root2) == 0)
        {
            printf("First condition: %d\n",  sol.countroots != CheckMassive[i].sol_a.countroots);
            printf("Second condition: %d\n", CompareFloats(sol.root1, CheckMassive[i].sol_a.root1) == 0);
            printf("Third condition: %d\n",  CompareFloats(sol.root2, CheckMassive[i].sol_a.root2) == 0);

            printf(RED " Check %d failed a=%g b=%g c=%g x1=%g x2=%g NR=%d" BLACK "\n",
                   i+1,
                   CheckMassive[i].par_a.a,
                   CheckMassive[i].par_a.b,
                   CheckMassive[i].par_a.c,
                   sol.root1,
                   sol.root2,
                   sol.countroots);
        }
        else printf(GREEN"Test %d passed successfully"BLACK"\n", i+1);
    }
    printf("Check is done\n");
}
