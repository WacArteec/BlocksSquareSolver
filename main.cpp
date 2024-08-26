/*! \file */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLACK   "\033[30m"      /* Black */

enum constantnumbers {Zero, One, Two, Infinity}; /**< constants of count of roots */

struct Solution /**< keep solves and their count of equation */
{
    int countroots;/**< the number of roots in equation */
    float root1, root2; /**< the roots of equation */
};

#include "GetCharReset.h"
#include "MathForSolve.h"
#include "MathForSolve.h"


struct Parameters /**< keep coefficients of equation */

{
    float a; /**< the senior coefficient of equation (x^2) */
    float b; /**< the second coefficient of equation (x) */
    float c; /**< the free term of equation (x^2) */
};

struct CheckNumbers /**< keep right coefficients and solutions of equation for tests */
{
    Parameters par_a; /**< coefficients of equation */
    Solution sol_a; /**< solutions and their count */
};

bool CompareFloats(const float a, const float b);
bool SolveManager(const Parameters par, Solution *const sol);
//int EqualSymbol(const char refer);
//void GetcharReset();
void Checker();
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

/** \brief decide is your equation linear or square
 *
 * \param par const Parameters (structure of coefficients)
 * \param sol Solution *const (structure of roots and their count)
 * \return bool
 *
 */
bool SolveManager(const Parameters par, Solution * const sol)  /**<  */
{
    assert(sol);
    assert(&par);
    const float a = par.a, b = par.b, c = par.c;

    if(CompareFloats(0, a)) return 1;
    else    return 0;
}

/** \brief solve square equation
 *
 * \param a const float
 * \param b const float
 * \param c const float
 * \param sol Solution *const
 * \return void
 *
 */
void SquareEquation(const float a, const float b, const float c, Solution *const sol)
{
    const float d = b*b - 4*a*c;

    if(CompareFloats(0, d))
    {
        sol->root1 = FabsZero(-b/(2*a));
        sol->countroots = One;
    }
    else if(d < 0)
    {
        sol->countroots = Zero;
    }
    else
    {
        const float sqrt_d = sqrt (d);
        sol->root1 = FabsZero(Min((-b - sqrt_d)/(2*a),(-b + sqrt_d)/(2*a)));
        sol->root2 = FabsZero(Max((-b - sqrt_d)/(2*a),(-b + sqrt_d)/(2*a)));
        sol->countroots = Two;
    }
}

/** \brief solve linear equation
 *
 * \param b const float (middle coefficient)
 * \param c const float (free term)
 * \param sol Solution *const (structure of roots and their count)
 * \return void
 *
 */
void LinearEquation(const float b, const float c, Solution *const sol)
{
    if(CompareFloats(0, b))
    {
        if(CompareFloats(0, c)) sol->countroots = Infinity;
        else sol->countroots = Zero;
    }
    else
    {
        sol->root1= FabsZero(-c/b);
        sol->countroots = One;
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
    size_t sizeCheck = sizeof(CheckMassive)/sizeof(CheckMassive[0]);

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
        else printf(GREEN "Test %d passed successfully"BLACK"\n", i+1);
    }
    printf("Check is done\n");
}
