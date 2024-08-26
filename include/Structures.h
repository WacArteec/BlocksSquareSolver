#ifndef STRUCTURES_H
#define STRUCTURES_H

enum constantnumbers {Zero, One, Two, Infinity}; /**< constants of count of roots */

struct Solution /**< keep solves and their count of equation */
{
    int countroots;/**< the number of roots in equation */
    float root1, root2; /**< the roots of equation */
};

struct Parameters /**< keep coefficients of equation */

{
    float a; /**< the senior coefficient of equation (x^2) */
    float b; /**< the second coefficient of equation (x) */
    float c; /**< the free term of equation (x^2) */
};

bool SolveManager(const Parameters par, Solution * const sol);

void SquareEquation(const float a, const float b, const float c, Solution *const sol);

void LinearEquation(const float b, const float c, Solution *const sol);

#endif // STRUCTURES_H
