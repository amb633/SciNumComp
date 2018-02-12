//
//  main.cpp
//  ECE4960Class5
//
//  Created by Ariana Bruno on 2/8/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <cmath>

double function_evaluated(double t){
    return exp(-t);
}

double forward_euler(double step_size, double t){
    double result = (1-step_size)*(function_evaluated(t-step_size));
    return result;
}

double backward_euler(double step_size, double t){
    double result = (1/(1-step_size))*(function_evaluated(t-step_size));
    return result;
}

double function_evaluated2(double x, double h=0.0){
    return pow(x + h,3);
}

double taylorApproxOrder1( double x, double h){
    return (function_evaluated2(x + h) - function_evaluated2(x))/h;
}

double richardson_approx(double x ,double h){
    double function_derivative = (-1/(2*h)*function_evaluated2(x+(2*h))) + ((-3/(2*h))*function_evaluated2(x)) + ((2/h)*function_evaluated2(x+h));
    return function_derivative;
}

double relError( double result, double known ){
    return abs(known - result)/known;
}

double richCoef_ErrorExpansion( double error_h, double error_2h ){
    return error_2h/error_h;
}

double richCoef_LocalApprox( double x, double h ){
    return (taylorApproxOrder1(x,4*h) - taylorApproxOrder1(x,2*h))/(taylorApproxOrder1(x,2*h) - taylorApproxOrder1(x,h));
}

int main(int argc, const char * argv[]) {
    //********************************************
    // Hacker Practice 3.2
    // Calculate the ground truth
    std::cout << "This is the ground results for f(t) = exp(-t) for 0<=t<=20: " << std::endl;
    for (int t=0; t<=20; t++){
        std::cout << function_evaluated(t) << std::endl;
    }
    
    
    // Calculate the forward euler and backward euler form t=0 to t=20
    double delta_t[3] = {0.5, 1.0, 2.0};
    for(int i=0; i<3; i++){
        std::cout << "This is the forward euler results for step size: " << delta_t[i] << std::endl;
        for (int t=0; t<=20; t++){
            std::cout << forward_euler(delta_t[i], t) << std::endl;
        }
    }
    
    // Calculate the forward euler and backward euler form t=0 to t=20
    for(int i=0; i<3; i++){
        std::cout << "This is the backward euler results for step size: " << delta_t[i] << std::endl;
        for (int t=0; t<=20; t++){
            std::cout << backward_euler(delta_t[i], t) << std::endl;
        }
    }
    
    //******************************************
    // Hacker Practice 3.3
    // Calculate the approximation for the f'(x=1) = 3 for f(x) = x^3 using Richardson Extrapolation
    std::cout << std::endl << "This is the richardson results, and error (h, result, rel err, richErr, approxErrH, approxErr2H, eta1, eta2): " << std::endl;
    
    for(int i=-4; i>= -40; i--){
        double h = pow(2,i);
        double result = richardson_approx(1, h);
        double relErr = relError(result, 3.0);
        double richApproxErr = abs(3.0-result);
        double approxErrH = abs(3.0-taylorApproxOrder1(1,h));
        double approxErr2H = abs(3.0-taylorApproxOrder1(1,2*h));
        double eta1 = richCoef_ErrorExpansion(abs(3.0-taylorApproxOrder1(1,h)), abs(3.0-taylorApproxOrder1(1,2*h)));
        double eta2 = richCoef_LocalApprox(1, h);
        
        std::cout << h << ", " << result << ", " << relErr << ", " << richApproxErr << ", " << approxErrH << ", " << approxErr2H << ", " << eta1 << ", " << eta2 << std::endl;
    }
    
    
    
    
    return 0;
}
