#include <math.h>
#include <assert.h>

#include "Structures.h"
#include "MathForSolve.h"

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

