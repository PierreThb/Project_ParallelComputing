/* 
 * File:   functions.h
 * Author: pierre
 *
 * Created on 8 décembre 2015, 15:52
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H
#define N 2
#define G 1
#define DELTA 0.1

#ifdef	__cplusplus
extern "C" {
#endif

    void addPos(float array[N], float val, int index);
    void addMass(float array[N], float val, int index);
    void addForce(float array[N][N], float val, int index1, int index2);
    void initForce(float arrayX[][],float arrayY[N][N]);


#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONS_H */

