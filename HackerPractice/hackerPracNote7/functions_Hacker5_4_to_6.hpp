//
//  functions_Hacker5_4_to_6.hpp
//  hackPracticeMar21
//
//  Created by Ariana Bruno on 4/23/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#ifndef functions_Hacker5_4_to_6_hpp
#define functions_Hacker5_4_to_6_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double func_f( double x);

double x_step( double x);

double calc_norm( vector<double>* x );

double func_v( vector<double>* x);

void calc_v_gradient( vector<double>* x, vector<double>* v_gradient );

void calc_hessian( vector<double>* x, vector<vector<double>>* H_matrix );

void calc_Newton_NL_dx( vector<double>* v_gradient, vector<vector<double>>* H_matrix, vector<double>* dx);

void vector_matrix_product(vector<vector<double>>* mat, vector<double>* vec, vector<double>* result);

double vector_dot( vector<double>* v1, vector<double>* v2 );

void new_x(vector<double>* x, vector<double>* dx);

double new_v_result(vector<double>* x, vector<double>* dx, vector<double>* v_gradient, vector<vector<double>>* H_matrix);

void scale_vec( vector<double>* x, double scalar, vector<double>* scale_x );

void steepest_decent_step(vector<double>* x, vector<double>* dx, vector<double>* t, double solution);

#endif /* functions_Hacker5_4_to_6_hpp */
