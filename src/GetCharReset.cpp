/*! \file */
#include <stdio.h>

#include "GetCharReset.h"

/** \brief checks whether the symbol matches the reference
 *
 * \param refer const char (reference symbol to enter)
 * \return int (compliance with the reference symbol)
 *
 */
int EqualSymbol(const char refer)
{
    int choise = ((getchar()) == refer);
    GetcharReset();
    return choise;
}

/** \brief clear your input file
 *
 * \return void
 *
 */
void GetcharReset()
{
    int reset = '\0';
    while((reset = getchar()) != EOF && reset != '\n');
}
