//
//  main.cpp
//  ECE4960Class4
//
//  Hacker Practice 3.1
//
//  Created by Ariana Bruno on 2/6/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <cmath>


//Function 1 to Approximate
double f1_of_x(double x, double h=0){
    return pow((x+h),2);
}

//Function 2 to Approximate
double f2_of_x(double x, double h=0){
    return pow((x+h),2) + pow(10,8);
}

//First Order Approximation
double approxOrder1(double f_of_x, double f_of_x_and_h, double h){
    return ((f_of_x_and_h - f_of_x)/ h);
}

//Second Order Approximation
double approxOrder2(double f_of_x_add_h, double f_of_x_minus_h, double h){
    return ((f_of_x_add_h) - (f_of_x_minus_h))/ (2*h);
}

// Calculates the relative error
double relError(double result, double known_value){
    return abs(known_value-result)/known_value;
}

int main(int argc, const char * argv[]) {
    
    //Hack Practice 1 of 1st order approximation for f1(x)
    std::cout << "This is the 1st order approximation for f1(x) (h, approx, abs_err, rel err): " << std::endl;
    for(int i=1; i<=18; i++){
        double h = pow(10,-i);
        double approximation = approxOrder1(f1_of_x(1), f1_of_x(1, h), h);
        double rel_err = relError(approximation, 2);
        double abs_err = abs(approximation - 2);
        std::cout << h << ", " << approximation << ", " << abs_err << ", " << rel_err << std::endl;
        
    }
    std::cout<<std::endl;
    
    //Hack Practice 3.1 of 1st order approximation for f2(x)
    std::cout << "This is the 1st order approximation for f2(x) (h, approx, abs_err, rel err): " << std::endl;
    for(int i=1; i<=18; i++){
        double h = pow(10,-i);
        double approximation = approxOrder1(f2_of_x(1), f2_of_x(1, h), h);
        double rel_err = relError(approximation, 2);
        double abs_err = abs(approximation - 2);
        std::cout << h << ", " << approximation << ", " << abs_err << ", " << rel_err << std::endl;
    }
    std::cout<<std::endl;
    
    //Hack Practice 3.1 of 2nd order approximation for f1(x)
    std::cout << "This is the 2nd order approximation for f1(x) (h, approx, abs_err, rel err): " << std::endl;
    for(int i=1; i<=18; i++){
        double h = pow(10,-i);
        double approximation = approxOrder2(f1_of_x(1, h), f1_of_x(1, -h), h);
        double rel_err = relError(approximation, 2);
        double abs_err = abs(approximation - 2);
        std::cout << h << ", " << approximation << ", " << abs_err << ", " << rel_err << std::endl;
    }
    std::cout<<std::endl;
    
    //Hack Practice 3.1 of 2nd order approximation for f2(x)
    std::cout << "This is the 2nd order approximation for f2(x) (h, approx, abs_err, rel err): " << std::endl;
    for(int i=1; i<=18; i++){
        double h = pow(10,-i);
        double approximation = approxOrder2(f2_of_x(1, h), f2_of_x(1, -h), h);
        double rel_err = relError(approximation, 2);
        double abs_err = abs(approximation - 2);
        std::cout << h << ", " << approximation << ", " << abs_err << ", " << rel_err << std::endl;
    }
    std::cout<<std::endl;

    
    return 0;
}
