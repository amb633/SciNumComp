//
//  newFunctionsNote7.hpp
//  HackerPractice7
//
//  Created by Ariana Bruno on 4/24/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#ifndef newFunctionsNote7_hpp
#define newFunctionsNote7_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const double N_D = (10e15); //in centimeters^-3
const double N_A = (10e17); //in centimeters^-3
const double h = 10e-3; //in centimeters
const double n_i = 1.5e10; //normalization term for N(x,y) in centimeter^-3
const double psi_0 = 1.0; // V
const double epsilon_si = 1.03e-12; //F/cm
const double L_D = 2.4e-3; // cm
const double V_T = 2.6e-2; // V
const double q = 1.6e-19; //columb

void create_Jacobian_and_F_Nonlin_PDE(vector<vector<double>>* J, vector<double>* F, vector<double>* psi, int rank);

#endif /* newFunctionsNote7_hpp */
