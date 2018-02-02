//
//  main.cpp
//  ECE4960Class3
//
//  Created by Ariana Bruno on 2/1/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>  //for the std::setprecision function


void isPositiveZero( double x){
    std::string answer;
    if (x > 0.0){
        answer = "True";
        std::cout << answer << ", " << x << " is positive" << std::endl;
    } else {
        answer = "False";
        std::cout << answer << ", " << x << " is not positive" << std::endl;
    }
}

void isNegativeZero( double x){
    std::string answer;
    if (x < 0.0){
        answer = "True";
        std::cout << answer << ", " << x << " is negative" << std::endl;
    } else {
        answer = "False";
        std::cout << answer << ", " << x << " is not negative" << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*
    //Hacker Pactice Part 1
    // Observe the exception handling on your platform
    double x = 0.0, y = 0.0, doubleResult1, doubleResult2;
    doubleResult1 = 1/x;
    doubleResult2 = y/x;
    
    //should return NaN and INF
    std::cout << doubleResult1 << ", " << doubleResult2 << std::endl;
     */
    
    /*
     long m=0, n=0, intResult1, intResult2;
    intResult1 = 1/m;
    intResult2=m/n;
    //returns an error from the compiler because INF cannot be represented by integer
    std::cout << intResult1 << ", " << intResult2 << std::endl;
     */
    
    /*
    //Hacker Practice 2
    isPositiveZero(1.0);
    isPositiveZero(-1.0);
    isPositiveZero(__DBL_MAX__);
    isPositiveZero(-1.0*__DBL_MAX__);
    isPositiveZero(__DBL_MIN__);
    isPositiveZero(-1.0*__DBL_MIN__);
    
    isNegativeZero(1.0);
    isNegativeZero(-1.0);
    isNegativeZero(__DBL_MAX__);
    isNegativeZero(-1.0*__DBL_MAX__);
    isNegativeZero(__DBL_MIN__);
    isNegativeZero(-1.0*__DBL_MIN__);
     */
    
    //Hacker Practice 3
    double x = 1.234567890123456;
    int i = 1;
    
    x *= pow(10,-307);
    
    for (i=1; i<20; i++) {
        x /= 10.0;
        std::cout << std::setprecision(32) << x << std::endl;
    }
    
    
    
    
    
    
    return 0;
}
