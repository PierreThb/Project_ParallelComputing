/* 
 * File:   forces_calc.h
 * Author: pierre
 *
 * Created on 7 décembre 2015, 18:09
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struct_Planet.h"
#

#ifndef FORCES_CALC_H
#define	FORCES_CALC_H
#define N 2
#define G 1
#define DELTA 0.1

#ifdef	__cplusplus
extern "C" {
#endif

void forces_calc(Planet Q, Planet K);


#ifdef	__cplusplus
}
#endif

#endif	/* FORCES_CALC_H */

