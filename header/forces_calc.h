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

#ifndef FORCES_CALC_H
#define	FORCES_CALC_H
#define N 4
#define G 1
#define DELTA 0.1

#ifdef	__cplusplus
extern "C" {
#endif

void forces_calc();
float position_cacl(float pos, float vel, float deltat);
float velocity_calc(float force, float masse, float deltat, float vel);
float total_forcesX(int index);
float total_forcesY(int index);
void compute_all_new_posX(planet* p1, planet* p2, planet* p3, planet* p4);
void compute_all_new_posY(planet* p1, planet* p2, planet* p3, planet* p4);
void compute_all_new_velX(planet* p1, planet* p2, planet* p3, planet* p4);
void compute_all_new_velY(planet* p1, planet* p2, planet* p3, planet* p4);

#ifdef	__cplusplus
}
#endif

#endif	/* FORCES_CALC_H */

