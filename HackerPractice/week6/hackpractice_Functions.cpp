//
//  hackpractice_Functions.cpp
//  hackerpractice_46
//
//  Created by Ariana Bruno on 4/23/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "hackpractice_Functions.hpp"

using namespace std;

void get_diagInv( vector<vector<double>>* input, vector<double>* diag ){
    for( int i=0; i<input->size(); i++){
        for( int j=0; j< (*input)[0].size(); j++){
            if( i == j){
                (*diag).push_back(1.0/(*input)[i][j]);
            }
        }
    }
}

void get_lower( vector<vector<double>>* input, vector<vector<double>>* lower ){
    (*lower) = (*input);
    for( int i=0; i<input->size(); i++){
        for( int j=0; j< (*input)[0].size(); j++){
            if( i >= j){
                (*lower)[i][j]=(0.0);
            }else{
                (*lower)[i][j]=-1.0*(*input)[i][j];
            }
        }
    }
}

void get_upper( vector<vector<double>>* input, vector<vector<double>>* upper ){
    (*upper) = (*input);
    for( int i=0; i<input->size(); i++){
        for( int j=0; j< (*input)[0].size(); j++){
            if( i <= j){
                (*upper)[i][j]=(0.0);
            }else{
                (*upper)[i][j]=-1.0*(*input)[i][j];
            }
        }
    }
}

void print_matrix(vector<vector<double>>* input){
    for( int i=0; i<input->size(); i++){
        for( int j=0; j< (*input)[0].size(); j++){
            cout << (*input)[i][j] << " ";
        }
        cout << endl;
    }
}

void print_vector(vector<double>* input){
    for( int i=0; i<input->size(); i++){
        cout << (*input)[i] << " ";
    }
}

void vectorSum(vector<double>* A, vector<double>* B, vector<double>* result){
    for( int i = 0; i<(*A).size(); i++){
        (*result)[i] = ((*A)[i] + (*B)[i]);
    }
}

void vectorProduct(vector<double>* A, vector<double>* B, vector<double>* result){
    for( int i = 0; i<(*A).size(); i++){
        (*result)[i] = ((*A)[i] * (*B)[i]);
    }
}

void vectorScale(vector<double>* A, double C, vector<double>* result){
    for( int i = 0; i<(*A).size(); i++){
        (*result)[i] = ((*A)[i] * C);
    }
}

void matrixSum(vector<vector<double>>* A, vector<vector<double>>* B, vector<vector<double>>* result){
    for( int i = 0; i<(*A).size(); i++){
        (*result).push_back({});
        for(int j=0; j<(*A)[0].size(); j++){
            (*result)[i].push_back((*A)[i][j] + (*B)[i][j]);
        }
    }
}

void matrixProduct( vector<vector<double>>* A, vector<double>* x , vector<double>* result){
    for( int i = 0; i<(*A).size(); i++){
        double product_element = 0.0;
        for(int j=0; j<(*A)[0].size(); j++){
            product_element += (*A)[i][j] * (*x)[j];
        }
        (*result)[i]=product_element;
    }
}

double calcResidualNorm( vector<double>* a, vector<double>* b ){
    double norm;
    double sumSquDiff = 0.0;
    for(int i=0; i<(*a).size(); i++){
        sumSquDiff += pow(((*a)[i]-(*b)[i]),2);
    }
    
    return norm = sqrt(sumSquDiff);
}

void jacobianSolver( vector<vector<double>>* A, vector<double>* b ){
    
    //    Jacobi Iterative Method
    vector<double> Dinv;
    get_diagInv(A, &Dinv);
    
    vector<vector<double>> L, U;
    get_lower(A, &L);
    
    get_upper(A, &U);
    
    vector<vector<double>> LU;
    matrixSum(&L, &U, &LU);
    
    vector<double> DInvB = Dinv; // initializing the size of the vector
    vectorProduct(&Dinv, b, &DInvB); // calculating the D^-1 * b vector
    
    vector<double> x = DInvB;
    
    vector<double> x_Jac = x;
    double norm_Jac = 1.0;
    
    while(norm_Jac > 1e-7){
        vector<double> product_LUx(x_Jac.size());
        matrixProduct(&LU, &x_Jac, &product_LUx);
        vectorSum(&product_LUx, b, &x_Jac);
        vectorProduct(&Dinv, &x_Jac, &x_Jac);
        
        vector<double> product_Ax(x_Jac.size());
        matrixProduct(A, &x_Jac, &product_Ax);
        norm_Jac = calcResidualNorm(&product_Ax, b);
        }
    
    cout << "Vector X: ";
    print_vector(&x_Jac);
    cout << "---> Residual Norm: " << norm_Jac << endl;
}

void SORSolver( vector<vector<double>>* A, vector<double>* b ){

    vector<double> Dinv;
    get_diagInv(A, &Dinv);

    vector<double> DInvB = Dinv; // initializing the size of the vector
    vectorProduct(&Dinv, b, &DInvB); // calculating the D^-1 * b vector

    vector<double> x = DInvB;

    //    SOR Method -- currently does not converge
    vector<double> x_SOR = x;
    double norm_SOR = 1.0;
    double omega = 0.5;
    size_t size = x_SOR.size();
    vector<double> r(size), product_Dr(size), product_Ax(size), neg_product_Ax(size), iter_adj(size);

    while(norm_SOR > 1e-7){

        //calculating A*x_k-1
        matrixProduct(A, &x_SOR, &product_Ax);

        //solving for r_k-1
        vectorScale(&product_Ax, -1.0, &neg_product_Ax);
        vectorSum(b, &neg_product_Ax, &r);

        //solving for iterative adjustment for x_k-1 w * D^-1 * r_k-1
        vectorProduct(&Dinv, &r, &product_Dr);
        vectorScale(&product_Dr, omega, &iter_adj);

        //solving for the current x_k
        vectorSum(&x_SOR, &iter_adj, &x_SOR);
        
        //calculating the residual norm for (b - Ax_k)
        vector<double> new_product_Ax(size);
        matrixProduct(A, &x_SOR, &new_product_Ax);
        norm_SOR = calcResidualNorm(&new_product_Ax, b);
        
        }
    
    cout << "Vector X: ";
    print_vector(&x_SOR);
    cout << "---> Residual Norm: " << norm_SOR << endl;
}
