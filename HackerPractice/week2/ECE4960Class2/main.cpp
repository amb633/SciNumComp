//
//  main.cpp
//  ECE4960Class2
//
//  Created by Ariana Bruno on 1/30/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <cmath>

int demo_int_overflow(int N){
    int product = 1;
    for(int i = 1; i <=20; i++ ){
        product = product*i;
    }
    return product;
}

void demo_quadratic1_precision( double a ){
    double b = pow(10,3);
    double c = pow(10,3);
    std::cout.precision(5);
    std::cout << std::scientific;
    
    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    std::cout << "-b + sqrt(b^2 - 4*a*c): " << (-b) + sqrt(pow(b,2) - 4*a*c) << std::endl;
    std::cout << "-b - sqrt(b^2 - 4*a*c): " << (-b) - sqrt(pow(b,2) - 4*a*c) << std::endl;
    std::cout << "2a: " << (2*a) << std::endl;
    std::cout << std::endl;
    
    
    
    double x1 = ((-b) - sqrt(pow(b,2) - (4*a*c)))/(2*a);
    double x2 = ((-b) + sqrt(pow(b,2) - (4*a*c)))/(2*a);
    
    std::cout << "Quadratic method 1 for a= " << a << " is: x1= " << x1 << " and x2= " << x2 << std::endl;
}


void demo_quadratic2_precision( double a ){
    double b = pow(10,3);
    double c = pow(10,3);
    std::cout.precision(5);
    std::cout << std::scientific;
    
    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    std::cout << "-b + sqrt(b^2 - 4*a*c): " << (-b) + sqrt(pow(b,2) - 4*a*c) << std::endl;
    std::cout << "-b - sqrt(b^2 - 4*a*c): " << (-b) - sqrt(pow(b,2) - 4*a*c) << std::endl;
    std::cout << "2c: " << (2*a) << std::endl;
    std::cout << std::endl;
    
    
    double x1 = (2*c)/(-b + sqrt(pow(b,2) - (4*a*c)));
    double x2 = (2*c)/(-b - sqrt(pow(b,2) - (4*a*c)));

    std::cout << "Quadratic method 2 for a= " << a << " is: x1= " << x1 << " and x2= " << x2 << std::endl;
    std::cout << std::endl;
    
    double est_x1 = -(b/a) + (c/b);
    double est_x2 = -c/b;
    std::cout << "Quadratic estimate for a= " << a << " is: x1_est= " << est_x1 << " and x2_est= " << est_x2 << std::endl;
}

int main(int argc, const char * argv[]) {

    std::cout.precision(9);


    //demonstrates that the 'int' will overflow once the length of the result is greater than 32 bits
    int int_result = demo_int_overflow(20);
    std::cout << "The overflow demo for 'int' is: "<< int_result << std::endl;
    std::cout << std::endl;

    //demonstrates that we get the same results from all 3 methods
    demo_quadratic1_precision(pow(10,-5));
    demo_quadratic2_precision(pow(10,-5));
    std::cout << std::endl;
    
    //demonstrates how the first method we can get the larger x result
    // where as the second method we get the smaller result
    // lastly the estimated results are able to provide the small and large result for x
    std::cout << "Now using a as 10^-20 " << std::endl;
    demo_quadratic1_precision(pow(10,-20));
    std::cout << std::endl;
    demo_quadratic2_precision(pow(10,-20));
    std::cout << std::endl;
    

    return 0;
}
