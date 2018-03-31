//
//  main.cpp
//  HackerMar27
//
//  Created by Ariana Bruno on 3/30/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double func_v(vector<double>* x, vector<double>* y, double a, double m){
    double sum = 0.0;
    for( int i = 0; i<x->size(); i++){
        double x_i = (*x)[i];
        double y_i = (*y)[i];
        sum = sum + pow(((a* pow(x_i, m))-y_i),2.0);
    }
    return sum;
}

double func_f1(vector<double>* x, vector<double>* y, double a, double m){
    double sum_term1 = 0.0;
    double sum_term2 = 0.0;
    for(int i = 0; i<x->size(); i++){
        double x_i = (*x)[i];
        double y_i = (*y)[i];
        
        sum_term1 = sum_term1 + pow(x_i, 2.0*m);
        sum_term2 = sum_term2 + (pow(x_i, m)*y_i);
    }
    sum_term1 = sum_term1*a;
    return sum_term1 - sum_term2;
}

double func_f2(vector<double>* x, vector<double>* y, double a, double m){
    double sum_term1 = 0.0;
    double sum_term2 = 0.0;
    for(int i = 0; i<x->size(); i++){
        double x_i = (*x)[i];
        double y_i = (*y)[i];
        
        sum_term1 = sum_term1 + log(x_i)*pow(x_i, 2.0*m);
        sum_term2 = sum_term2 + log(x_i)*pow(x_i, m)*y_i;
    }
    sum_term1 = sum_term1*pow(a,2.0);
    sum_term2 = sum_term2*a;
    return sum_term1 - sum_term2;
}

double df1_dm(vector<double>* x, vector<double>* y, double a, double m){
    double r1 = func_f1(x, y, a, m);
    double r2 = func_f1(x, y, a, (m+(1e-4*m)));
    return (r1 - r2)/(1e-4*m);
}

double df2_dm(vector<double>* x, vector<double>* y, double a, double m){
    double r1 = func_f2(x, y, a, m);
    double r2 = func_f2(x, y, a, (m+(1e-4*m)));
    return (r1 - r2)/(1e-4*m);
}

void neg_inv_matrix(vector<vector<double>>* H){
    double a, b, c, d;
    a = (*H)[0][0];
    b = (*H)[0][1];
    c = (*H)[1][0];
    d = (*H)[1][1];
    
    double scalar = (1/((a*d)-(b*c)));
    
    (*H)[0][0] = scalar * d;
    (*H)[0][1] = scalar * -1.0 * b;
    (*H)[1][0] = scalar * -1.0 * c;
    (*H)[1][1] = scalar * a;
    
}

void func_H(vector<double>* x, vector<double>* y, double a, double m, vector<vector<double>>* H_neg_inv){
    double sum_term1 = 0.0;
    double sum_term2 = 0.0;
    double sum_term3 = 0.0;
    
    for(int i = 0; i<x->size(); i++){
        double x_i = (*x)[i];
        double y_i = (*y)[i];
        
        sum_term1 = sum_term1 + pow(x_i, 2.0*m);
        sum_term2 = sum_term2 + log(x_i)*pow(x_i, 2.0*m);
        sum_term3 = sum_term3 + log(x_i)*pow(x_i, m)*y_i;
    }
    double H_term1, H_term2, H_term3, H_term4;
    vector<double> H_row1, H_row2;
    H_term1 = sum_term1;
    H_term3 = (sum_term2*2.0*a) - sum_term3;
    
    H_term2 = df1_dm(x, y, a, m);
    H_term4 = df2_dm(x, y, a, m);
    
    H_row1 = {H_term1, H_term2};
    H_row2 = {H_term3, H_term4};
    H_neg_inv->push_back(H_row1);
    H_neg_inv->push_back(H_row2);
    neg_inv_matrix(H_neg_inv);
    
}

void new_dx(vector<vector<double>> *H_neg_inv, vector<double>* parameters, vector<double>* dx){
    vector<vector<double>> H_current = *H_neg_inv;
    for( int i = 0; i< (*H_neg_inv).size(); i++ ){
        double sum = 0.0;
        for( int j = 0; j< (*parameters).size(); j++){
            sum = sum + ((*H_neg_inv)[i][j]  * (*parameters)[j]);
        }
        dx->push_back(sum);
    }
}

void add_vector( vector<double>* v1, vector<double>* v2 ){
    for( int i = 0; i<v1->size(); i++ ){
        (*v1)[i] = (*v1)[i] + (*v2)[i];
    }
}
        

int main(int argc, const char * argv[]) {
    double a_0 = 2;
    double m_0 = 1;
    vector<double> x = { 1.0, 4.5, 9.0, 20.0, 74.0, 181.0 };
    vector<double> y = { 3.0, 49.4, 245.0, 1808.0, 2.2e4, 7.4e4};
    vector<double> current_param = {a_0, m_0};
    double initial_result = func_v(&x, &y, a_0, m_0);

    for(int i = 0; i <100 ; i++ ){
        vector<vector<double>> H_iter;
        func_H(&x, &y, current_param[0], current_param[1], &H_iter);
        
        vector<double> dx;
        cout << "paramters= (";
        for( int i = 0; i<current_param.size(); i++){
            cout << current_param[i] << ", ";
        }
        cout << "), ";
        vector<double> current_f = {func_f1(&x, &y, current_param[0], current_param[1]), func_f2(&x, &y, current_param[0], current_param[1])};
        new_dx(&H_iter, &current_f, &dx);
        
        cout << "dx= (";
        for( int i = 0; i<dx.size(); i++){
            cout << dx[i] << ", ";
        }
        cout << "), ";
        cout << "result= ";
        double result = func_v(&x, &y, current_param[0], current_param[1]);
        cout << result << ", ";
        cout << endl;
        add_vector(&current_param, &dx);
    }
    
    return 0;
}
