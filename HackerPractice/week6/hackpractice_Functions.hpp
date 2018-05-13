//
//  hackpractice_Functions.hpp
//  hackerpractice_46
//
//  Created by Ariana Bruno on 4/23/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#ifndef hackpractice_Functions_hpp
#define hackpractice_Functions_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void get_diagInv( vector<vector<double>>* input, vector<double>* diag );

void get_lower( vector<vector<double>>* input, vector<vector<double>>* lower );

void get_upper( vector<vector<double>>* input, vector<vector<double>>* upper );

void print_matrix(vector<vector<double>>* input);

void print_vector(vector<double>* input);

void vectorSum(vector<double>* A, vector<double>* B, vector<double>* result);

void vectorProduct(vector<double>* A, vector<double>* B, vector<double>* result);

void vectorScale(vector<double>* A, double C, vector<double>* result);

void matrixSum(vector<vector<double>>* A, vector<vector<double>>* B, vector<vector<double>>* result);

void matrixProduct( vector<vector<double>>* A, vector<double>* x , vector<double>* result);

double calcResidualNorm( vector<double>* a, vector<double>* b );

void jacobianSolver( vector<vector<double>>* A, vector<double>* b );

void SORSolver( vector<vector<double>>* A, vector<double>* b );

#endif /* hackpractice_Functions_hpp */
