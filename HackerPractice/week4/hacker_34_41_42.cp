//
//  main.cpp
//  Week4
//
//  Created by Ariana Bruno on 2/13/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>

using namespace std;

typedef struct Compressed_Row_Matrix{
    vector<int> value;
    vector<size_t> row_p;
    vector<int> col_id;
}comp_r_mat;

typedef struct number{
    long double value;
    long double integer;
    long double fraction;
    int start;
    int end;
} number;

vector< vector<int> > input_vector = {{1 , 2, 0, 0 , 3}, {4 , 5, 6, 0, 0}, {0 , 7, 8, 0, 9}, {0, 0, 0, 10, 0}, {11 , 0, 0, 0 , 12}};

int retrieveElement( comp_r_mat* input, int row_id, int col_id){
    int element = 0;
    size_t row_non_zero_start = input->row_p[row_id];
    size_t row_non_zero_end = input->row_p[row_id + 1];
    for(size_t p = row_non_zero_start; p< row_non_zero_end; p++){
        if( input->col_id[p] == col_id ){
            element = input->value[p];
        }
    }
    return element;
}

comp_r_mat construct_compressed_matrix( vector<vector<int>> input ){
    comp_r_mat mat_A;
    size_t rows = input.size();
    size_t columns = input[0].size();
    int non_zeros = 0;
    mat_A.row_p.push_back(non_zeros);
    
    for (int i = 0; i<rows; i++ ){
        for (int j = 0; j<columns; j++ ){
            if(input[i][j] != 0){
                mat_A.value.push_back(input[i][j]);
                mat_A.col_id.push_back(j);
                non_zeros++;
            }
        }
        mat_A.row_p.push_back(non_zeros);
    }
    return mat_A;
}

int productAx( comp_r_mat* A, vector<int>* x, vector<int>* b ){
    if(A->row_p.size()-1 == x->size()){
        for(int i = 0; i < A->row_p.size()-1; i++){
            int product = 0;
            for(int j = 0; j < A->row_p.size()-1; j++){
                int value = (retrieveElement(A, i, j));
                value =  value * (*x)[j];
                if( isinf(value) || isinf(-1*value)){
                    return 2;
                } else if ( isnan(value) ){
                    return 3;
                }
                product = product + value;
            }
            b->push_back(product);
        }
        return 0;
    }
    return 1;
}

double function_evaluated (double x){
    return exp(x);
}

double error_calc (double approx){
    double ground_truth = 2.3504;
    return (ground_truth-approx);
}

double RectApprox( double x_lo, double x_hi, double h ){
    double approx = 0.0;
    for (double x_k = x_lo; x_k <=(x_hi-h); x_k+=h){
        approx = approx + (h*(function_evaluated(x_k)));
    }
    return approx;
}

double TrapApprox ( double x_lo, double x_hi, double h){
    double approx = 0.0;
    for (double x_k = x_lo; x_k <=(x_hi-h); x_k+=h){
        approx = approx + (h*((0.5*function_evaluated(x_k))+(0.5*function_evaluated(x_k+h))));
    }
    return approx;
}

double MidptApprox ( double x_lo, double x_hi, double h){
    double approx = 0.0;
    for (double x_k = x_lo; x_k <=(x_hi-h); x_k+=h){
        approx = approx + (h*(function_evaluated(x_k+(0.5*h))));
    }
    return approx;
}

double SimpsonApprox ( double x_lo, double x_hi, double h){
    double approx = 0.0;
    for (double x_k = x_lo; x_k <=(x_hi-h); x_k+=h){
        approx = approx + h*(((1.0/4.0)*function_evaluated(x_k))+((4.0/6.0)*function_evaluated(x_k+(0.5*h))) + ((1.0/4.0)*function_evaluated(x_k+h)));
    }
    return approx;
}

double TwoPointGausApprox ( double x_lo, double x_hi, double h){
    double approx = 0.0;
    for (double x_k = x_lo; x_k <=(x_hi-h); x_k+=h){
        approx = approx + h*((0.5*function_evaluated((x_k+(0.5*h))-((1.0/(2.0*sqrt(3.0)))*h))) + (0.5*function_evaluated((x_k+(0.5*h))+((1.0/(2.0*sqrt(3.0)))*h))));
    }
    return approx;
}


int main(int argc, const char * argv[]) {
    //Hacker Practice 3.4
    double x_lo = -1.0;
    double x_hi = 1.0;
    double h = 0.1;
    cout << "(Quadrature Schemes, Numerical Approximation, Error) = " << endl << endl;
    double rect_approx = RectApprox(x_lo, x_hi, h);
    cout << "(Rectangle Approximation, " << rect_approx << ", " << error_calc(rect_approx) << ") " << endl;
    double trapezoid_approx = TrapApprox(x_lo, x_hi, h);
    cout << "(Trapezoid Approximation, " << trapezoid_approx << ", " << error_calc(trapezoid_approx) << ") " << endl;
    double mid_pt_approx = MidptApprox(x_lo, x_hi, h);
    cout << "(Mid-point Approximation, " << mid_pt_approx << ", " << error_calc(mid_pt_approx) << ") " << endl;
    double simpson_approx = SimpsonApprox(x_lo, x_hi, h);
    cout << "(Simpson Approximation, " << simpson_approx << ", " << error_calc(simpson_approx) << ") " << endl;
    double two_pt_gaus_approx = TwoPointGausApprox(x_lo, x_hi, h);
    cout << "(Two-point Gaussian Approximation, " << two_pt_gaus_approx << ", " << error_calc(two_pt_gaus_approx) << ") " << endl;
    cout << endl;
    
    //Hacker Practice 4.1
    comp_r_mat mat_a = construct_compressed_matrix(input_vector);
    cout << "This is the values in mat_a: " << endl;
    for (int n = 0; n<mat_a.value.size() ; n++){
        cout << mat_a.value[n] << ", ";
    }
    cout << endl;
    cout << "This is the row_p in mat_a: " << endl;
    for (int n = 0; n<mat_a.row_p.size() ; n++){
        cout << mat_a.row_p[n] << ", ";
    }
    cout << endl;
    cout << "This is the col_id in mat_a: " << endl;
    for (int n = 0; n<mat_a.col_id.size() ; n++){
        cout << mat_a.col_id[n] << ", ";
    }
    cout << endl;
    
     //Hacker Practice 4.2
    int element_0_4 = retrieveElement(&mat_a, 0, 4);
    cout << "This is the element at 0,4: " << element_0_4 << endl;
    int element_4_1 = retrieveElement(&mat_a, 4, 1);
    cout << "This is the element at 4,1: " << element_4_1 << endl;
    int element_2_2 = retrieveElement(&mat_a, 2, 2);
    cout << "This is the element at 2,2: " << element_2_2 << endl;
    
    vector<int> x_test = {5,4,3,2,1};
    vector<int> b_test;
    int check_product = productAx(&mat_a, &x_test, &b_test);
    cout << check_product << endl;
    if (check_product == 0) {
        cout << "This is the resulting product of A*x = b, b= { ";
        for (int i = 0; i<b_test.size(); i++){
            cout << b_test[i] << " ";
        }
        cout << "} " << endl;
    }
    
    return 0;
}
