//
//  newFunctionsNote7.cpp
//  HackerPractice7
//
//  Created by Ariana Bruno on 4/24/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "newFunctionsNote7.hpp"


void create_Jacobian_and_F_Nonlin_PDE(vector<vector<double>>* J, vector<double>* F, vector<double>* psi, int rank){
    for ( int i = 0; i<=rank; i++){
        double diag_term = -4.0 - pow(h,2.0)*(exp(-1.0*(*psi)[i]) - exp((*psi)[i]));
        vector<double> row_vector(rank);
        fill(row_vector.begin(),row_vector.end(), 0.0);
        int index = i;
        double F_val = 0.0;
        double non_lin;
        switch (i) {
            case 0:
                row_vector[index] = diag_term;
                row_vector[index + 1] = 1;
                row_vector[index + 3] = 1;
                non_lin = pow(h,2.0)*(exp(-1*(*psi)[i]) - exp((*psi)[i]) + N_D);
                F_val = -1.0*((-4*(*psi)[i]) + (*psi)[i+1] + (*psi)[i+3] + non_lin + 2.0*psi_0);
                F->push_back(F_val);
                break;
                
            case 1:
                row_vector[index - 1] = 1;
                row_vector[index] = diag_term;
                row_vector[index + 1] = 1;
                row_vector[index + 3] = 1;
                F_val = -1.0*((*psi)[i-1] + (-4*(*psi)[i]) + (*psi)[i+1] + (*psi)[i+3] + pow(h,2.0)*(exp(-1*(*psi)[i]) - exp((*psi)[i]) + N_D));
                F->push_back(F_val);
                break;
                
            case 2:
                row_vector[index - 1] = 1;
                row_vector[index] = diag_term;
                row_vector[index + 3] = 1;
                F_val = -1.0*((*psi)[i-1] + (-4*(*psi)[i]) + (*psi)[i+3] + pow(h,2.0)*(exp(-1*(*psi)[i]) - exp((*psi)[i]) - N_A));
                F->push_back(F_val);
                break;
                
            case 3:
                row_vector[index - 3] = 1;
                row_vector[index] = diag_term;
                row_vector[index + 1] = 1;
                row_vector[index + 3] = 1;
                F_val = -1.0*((*psi)[i-3] + (-4*(*psi)[i]) + (*psi)[i+1] + (*psi)[i+3] + pow(h,2.0)*(exp(-1*(*psi)[i]) - exp((*psi)[i]) + N_D));
                F->push_back(F_val);
                break;
                
            case 4:
                row_vector[index - 3] = 1;
                row_vector[index - 1] = 1;
                row_vector[index] = diag_term;
                row_vector[index + 1] = 1;
                row_vector[index + 3] = 1;
                F_val = -1.0*((*psi)[i-3] + (*psi)[i-1] + (-4*(*psi)[i]) + (*psi)[i+1] + (*psi)[i+3] + pow(h,2.0)*(exp(-1*(*psi)[i]) - exp((*psi)[i]) - N_A));
                F->push_back(F_val);
                break;
            case 5:
                row_vector[index - 3] = 1;
                row_vector[index - 1] = 1;
                row_vector[index] = diag_term;
                row_vector[index + 3] = 1;
                F_val = -1.0*((*psi)[i-3] + (*psi)[i-1] + (-4*(*psi)[i]) + (*psi)[i+3] + pow(h,2.0)*(exp(-1*(*psi)[i]) - exp((*psi)[i]) - N_A));
                F->push_back(F_val);
                break;
                
            case 6:
                row_vector[index - 3] = 1;
                row_vector[index] = diag_term;
                row_vector[index + 1] = 1;
                F_val = -1.0*((*psi)[i-3] + (-4*(*psi)[i]) + (*psi)[i+1] + pow(h,2.0)*(exp(-1*(*psi)[i]) - exp((*psi)[i]) - N_A));
                F->push_back(F_val);
                break;
                
            case 7:
                row_vector[index - 3] = 1;
                row_vector[index - 1] = 1;
                row_vector[index] = diag_term;
                row_vector[index + 1] = 1;
                F_val = -1.0*((*psi)[i-3] + (*psi)[i-1] + (-4*(*psi)[i]) + (*psi)[i+1] + pow(h,2.0)*(exp(-1*(*psi)[i]) - exp((*psi)[i]) - N_A));
                F->push_back(F_val);
                break;
                
            case 8:
                row_vector[index - 3] = 1;
                row_vector[index - 1] = 1;
                row_vector[index] = diag_term;
                F_val = -1.0*((*psi)[i-3] + (*psi)[i-1] + (-4*(*psi)[i]) + pow(h,2.0)*(exp(-1*(*psi)[i]) - exp((*psi)[i]) - N_A));
                F->push_back(F_val);
                break;
                
            default:
                break;
        }
        J->push_back(row_vector);
    }
}


