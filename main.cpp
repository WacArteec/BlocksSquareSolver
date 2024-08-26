/*! \file */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "GetCharReset.h"
#include "MathForSolve.h"
#include "MathForSolve.h"
#include "Tests.h"
#include "Structures.h"

bool CompareFloats(const float a, const float b);
bool SolveManager(const Parameters par, Solution *const sol);
//int EqualSymbol(const char refer);
//void GetcharReset();
void LinearEquation(const float b, const float c, Solution * const sol);
void PrintSolves(const Solution sol);
void UserInputAndCheck(float coef[3]);
void SquareEquation(const float a, const float b, const float c, Solution * const sol);
//float Min(const float a, const float b);
//float Max(const float a, const float b);
//float FabsZero(const float a);

/** \brief allows to choose to enter your parameters or conduct a check
 *
 * \return int
 *
 */
int main()
{
    printf("this is solver of square equals from WacArteec \n");

    while(1)
    {
        struct Parameters par; /**< keep coefficients */
        struct Solution sol; /**< keep solutions and count of roots */

        par = {0, 0, 0};
        sol = {.countroots = 0, .root1 = 0, .root2 = 0};

        printf("To enter your parameters press e or press another button to check solver\n");

        if(EqualSymbol('e'))
        {
            float coef[3] = {0, 0, 0};
            UserInputAndCheck(coef);
            par.a = coef[0];
            par.b = coef[1];
            par.c = coef[2];
            if(SolveManager(par, &sol)) LinearEquation(par.b, par.c, &sol);
            else SquareEquation(par.a, par.b, par.c, &sol);
            PrintSolves(sol);
        }
        else
        {
            Checker();
        }

        GetcharReset();
        printf("\nEnter r to repeat or another key to escape\n");

        if(!EqualSymbol('r')) break;
    }
return 0;
}

/** \brief enter your parameters and check is it right, if not, is appear a message about it, and you can repeat entering
 *
 * \param coef[3] float (array of coefficients)
 * \return void
 *
 */
void UserInputAndCheck(float coef[3]) /**< */
{
    for(int i = 0; i < 3; i++)
    {
        char a;
        printf("Enter Parameter %c:\n",'a'+i);
        if(scanf("%g%c", &coef[i], &a) != 2)
        {
            GetcharReset();
            printf("You can enter only numbers\n");
            i--;
        }
        else if(!isfinite(coef[i]))
        {
            printf("You can enter only numbers\n");
            i--;
        }
        else if(a!='\n' && !EqualSymbol('\n'))
        {
            printf("You can enter only numbers\n");
            i--;
        }
    }
}

/** \brief print solves of equation from less to largest root
 *
 * \param sol const Solution (structure of roots and their count)
 * \return void
 *
 */
void PrintSolves(const Solution sol)
{
    switch(sol.countroots)
    {
        case Zero:  printf("no solves\n");
                    break;

        case One:   printf("x= %.5f\n", sol.root1);
                    break;

        case Two:   printf("x1 = %.5f x2 = %.5f\n", sol.root1, sol.root2);
                    break;

        case Infinity:  printf("infinity count of solves\n");
                        break;

        default:    printf("main(): ERROR: count of roots = %d\n", sol.countroots);
                    break;
    }
}



