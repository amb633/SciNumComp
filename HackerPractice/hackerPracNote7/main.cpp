//
//  main.cpp
//  HackerPractice7
//
//  Created by Ariana Bruno on 4/23/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "hackpractice_Functions.hpp"
#include "functions_Hacker5_4_to_6.hpp"
#include "newFunctionsNote7.hpp"

bool checkForInfInVector( vector<double>* v){
    bool check = false;
    for( int i = 0; i<v->size(); i++){
        double inf = isinf((*v)[i]);
        if(inf){
            check = true;
            break;
        }
    }
    return check;
}

void line_search(vector<double>* d_psi, vector<double>* psi, vector<vector<double>>* J, vector<double>* F, double& t){
    if( calc_norm(F) > 1e-2 ){
        vector<double> scaled_dpsi;
        vector<double> scaled_psi(psi->size());
        scale_vec(d_psi, t, &scaled_dpsi);
        vectorSum(psi, &scaled_dpsi, &scaled_psi);
        vector<vector<double>> scaled_J;
        vector<double> scaled_F;
        create_Jacobian_and_F_Nonlin_PDE(&scaled_J, &scaled_F, &scaled_psi, (int)scaled_psi.size());
        if(checkForInfInVector(&scaled_F)){
            t *=0.5;
            line_search(d_psi, psi, J, F, t);
        }else{
            double orig_F_norm = calc_norm(F);
            double scaled_F_norm = calc_norm(&scaled_F);
            if( scaled_F_norm <= orig_F_norm){
                (*F) = scaled_F;
                (*J) = scaled_J;
                (*psi) = scaled_psi;
                (*d_psi) = scaled_dpsi;
                return;
            }else{
                if( t/2.0 == 0.0 ){
                    (*F) = scaled_F;
                    (*J) = scaled_J;
                    (*psi) = scaled_psi;
                    (*d_psi) = scaled_dpsi;
                    return;
                }
                t = t/2;
                line_search(d_psi, psi, J, F, t);
            }
        }
        
    }
    return;
}

int main(int argc, const char * argv[]) {
    vector<vector<double>> A1 = {{-2, 1, 0, 0}, {1, -2, 1, 0}, {0, 1, -2, 1}, {0, 0, 1, -2}};
    vector<vector<double>> A2 = {{-2, 1, 0, 0}, {1, -2, 1, 0}, {0, 1, -2, 1}, {0, 0, 1, -1}};
    vector<double> b = {-1, 0, 0, 0};
    
    cout << endl <<  "Hacker Practice 7.1 for psi(x=0) = 1 and psi(x=L) = 0" << endl;
    jacobianSolver(&A1, &b);
    
    cout << endl << "Hacker Practice 7.1 for psi(x=0) = 1 and psi(x=L) => psi_N-1 = psi_N" << endl;
    jacobianSolver(&A2, &b);
    
//    **************Newton Method for Non-linear Optimization**************
//    with an initial guess of (0,0) the dx goes to 0 after the first iteration because of the initial guesses.
//    need to overestimate the values so that they converge back to the solution. For finding (-1, 1) the
//    initial guess needs to guess a value of larger negative value such as (-2, 2) and for finding (1, 1), could have
//    initial guess of (2, 2). These guess will converge to the correct value.
    
    vector<double> psi = {1.0,1.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0};
    
    for( int k = 0; k<1000; k++){
        vector<double> dpsi_vec, new_psi;
        vector<vector<double>> Jacobian_Nonlin_PDE;
        vector<double> F;
        create_Jacobian_and_F_Nonlin_PDE(&Jacobian_Nonlin_PDE, &F, &psi, psi.size());
        calc_Newton_NL_dx(&F, &Jacobian_Nonlin_PDE, &dpsi_vec);
        double t = 0.5;
        line_search(&dpsi_vec, &psi, &Jacobian_Nonlin_PDE, &F, t);
        cout << "x = [";
        for ( int i =0; i< psi.size(); i++){
            cout << psi[i] <<",";
        }
        cout << "], ";
        cout << "delta_x = [";
        for ( int i =0; i< dpsi_vec.size(); i++){
            cout << dpsi_vec[i] <<",";
        }
        cout << "], ";
        cout << "t = " << t;
        cout << " norm(F) = " << calc_norm(&F) << endl;
//        cout << endl;
        bool convergence = true;
        for(int i = 0; i<=dpsi_vec.size(); i++){
            if( abs(dpsi_vec[i]) > 1e-9 ){
                convergence = false;
            }
        }
        if(convergence == true){
            cout << "Result has stopped updating and converged with f(x) at x = [";
            for ( int i =0; i< psi.size(); i++){
                cout << psi[i] <<",";
            }
            cout << "] " << endl;
            break;
        }
    
    }
    cout << endl;

    return 0;
}
