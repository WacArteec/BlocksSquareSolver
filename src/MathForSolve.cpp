/*! \file */

#include "MathForSolve.h"
#include <math.h>

const float COMPARECONST = 1e-5; /**< for comparing two numbers */

/** \brief compare two float number
 *
 * \param a const float
 * \param b const float
 * \return bool (1 if number are equal, 0 if aren't)
 *
 */
bool CompareFloats(const float a, const float b) /**<  */
{
    return(fabs(a - b) < COMPARECONST);
}

/** \brief helps not to print -0, if number is zero, function takes the modulus of number
 *
 * \param a const float
 * \return float (modulus of number if it zero, number if it's not)
 *
 */
float FabsZero(const float a)
{
    if (CompareFloats(0,a)) return fabs(a);
    else return a;
}

/** \brief decide which number is less
 *
 * \param a const float
 * \param b const float
 * \return float (the less of number)
 *
 */
float Min(const float a, const float b)
{
    if(a < b) return a;
    else return b;
}

/** \brief decide which number is bigger
 *
 * \param a const float
 * \param b const float
 * \return float (the biggest of two numbers)
 *
 */
float Max(const float a, const float b)
{
    if(a > b) return a;
    else return b;
}
