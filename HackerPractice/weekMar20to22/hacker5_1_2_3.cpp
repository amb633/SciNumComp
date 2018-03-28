//
//  main.cpp
//  weekMar20
//
//  Created by Ariana Bruno on 3/20/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double func5_1(double x){
    return exp(x)-1.0;
}

double func5_1_2a(double x, double y){
    return exp(x)-exp(y);
}

double func5_1_2b(double x, double y){
    return exp(x)+exp(y);
}

double find_root_1D(double min, double max, double result){
    double midpt = (max + min)/2.0;
    double midpt_result = func5_1(midpt);
    if( abs(midpt_result - result) > 1e-7){
        if ( result <= midpt_result && result >= func5_1(min)){
            midpt = find_root_1D(min, midpt, result);
        }else if ( result > midpt_result && result <= func5_1(max)){
            midpt = find_root_1D(midpt, max, result);
        }
    }
    return midpt;
}

void find_root_2D(double x_min, double x_max, double y_min, double y_max, double result1, double result2){
    double x_midpt = (x_max + x_min)/2.0;
    double y_midpt = (y_max + y_min)/2.0;
    double midpt_result1 = func5_1_2a(x_midpt, y_midpt);
    double midpt_result2 = func5_1_2b(x_midpt, y_midpt);
    if( abs(midpt_result1 - result1) > 1e-7 ){
        if ( result1 <= midpt_result1 && result1 >= func5_1_2a(x_min, y_min)){
            find_root_2D(x_min, x_midpt, y_min, y_midpt, result1, result2);
        }else if ( result1 > midpt_result1 && result1 <= func5_1_2a(x_max, y_max)){
            find_root_2D(x_midpt, x_max, y_midpt, y_max, result1, result2);
        }
    } else if (abs(midpt_result2 - result2) > 1e-7 ){
        if ( result2 <= midpt_result2 && result2 >= func5_1_2b(x_min, y_min)){
            find_root_2D(x_min, x_midpt, y_min, y_midpt, result1, result2);
        }else if ( result2 > midpt_result2 && result2 <= func5_1_2b(x_max, y_max)){
            find_root_2D(x_midpt, x_max, y_midpt, y_max, result1, result2);
        }
        
    } else{
        cout << "This is the midpt value: x-:" << x_midpt << " and y: " << y_midpt << endl;
        cout << "Result(" << x_midpt << ", " << y_midpt << ") is equal to eq1 = " << func5_1_2a(x_midpt, y_midpt) << " and eq2 = " << func5_1_2b(x_midpt, y_midpt) << endl;
    }
}

double func(double x){
    return exp(50.0*x)-1.0;
}

double func_inv(double x){
    return 50.0*exp(50.0*x);
}

void Newton_Raphson_Method(double x, double solution, int iter = 0){
    
    double delta_x = -1.0*func(x)/func_inv(x);
    cout << " x= " << x << ", delta_x= " << delta_x << ", f(x)= " << func(x) << endl;
    if( abs(func(x) - solution) < 1e-7 ){
        cout << "The convergence has occured at x= " << x << " and f(x) = " << func(x) << " at iteration: " << iter << endl;
        return;
    }
    
    x = x + delta_x;
    iter++;
    Newton_Raphson_Method(x, solution, iter);
}

double find_t(double x, double dx, double result){
    double min = abs(func(x + dx) - result);
    double min_t = 1.0;
    for( int i = 0; i <= 10; i++){
        double t = pow(2, -1.0*i);
        double t_result =  abs(func(x + t*dx) - result);
        if( t_result < min ){
            min = t_result;
            min_t = t;
        }
    }
    return min_t;
}

void Line_Search_t_Newton(double x, double solution, int iter = 0){
    
    double delta_x = -1.0*func(x)/func_inv(x);
    cout << " x= " << x << ", delta_x= " << delta_x << ", f(x)= " << func(x) << endl;
    if( abs(func(x) - solution) < 1e-7 ){
        cout << "The convergence has occured at x= " << x << " and f(x) = " << func(x) << " at iteration: " << iter << endl;
        return;
    }
    double t = find_t(x, delta_x, solution);
    x = x + t*delta_x;
    iter++;
    Newton_Raphson_Method(x, solution, iter);
}


//void find_min_t(double x, double dx, double* t_min_f, double* min_f){
//    for(int i = 0; i <=6; i++){
//        double t = pow(2,-1.0*i);
//        double f = abs(func(x + t*dx));
//
//        if( f < *min_f ){
//            *min_f = f;
//            *t_min_f = t;
//        }
//    }
//}

int main(int argc, const char * argv[]) {
//    hacker practice 5.1
    double range_min = -5.0;
    double range_max = 10.0;
    double solution_val = 0.0;
    double root = find_root_1D(range_min, range_max, solution_val);
    cout << "this is the root value: " << root << "with result = " << func5_1(root) << endl;
    find_root_2D(-5, 10, -5, 10, 0.0, 2.0);
    
//    hacker practice 5.2
    double x0_1 = 1;
    double x0_2 = 10;
    double solution = 0.0;
    cout << endl << "For Newton Raphson Method for x_0 = 1: " << endl;
    Newton_Raphson_Method(x0_1, solution);
    cout << endl << "For Newton Raphson Method for x_0 = 10: " << endl;
    Newton_Raphson_Method(x0_2, solution);
    
//    hacker practice 5.3
    double x_0 = 10.0;
    double x = x_0;
    Line_Search_t_Newton(x, 0.0);
    
    
    
    return 0;
}
