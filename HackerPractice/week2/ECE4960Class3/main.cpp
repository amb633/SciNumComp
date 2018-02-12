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
#include <limits>  //for the infinity();


void isPositiveZero( float x){
    std::string answer;
    float zero_pos = +0.0;
    if (std::signbit(x) == 0){
        answer = "True";
        std::cout << answer << ", " << x << " is positive" << std::endl;
    } else {
        answer = "False";
        std::cout << answer << ", " << x << " is not positive" << std::endl;
    }
}

void isNegativeZero( float x){
    std::string answer;
    if (std::signbit(x) == 1){
        answer = "True";
        std::cout << answer << ", " << x << " is negative" << std::endl;
    }else {
        answer = "False";
        std::cout << answer << ", " << x << " is not negative" << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    //Hacker Pactice 2.2
    // Observe the exception handling on your platform
    double x = 0.0, y = 0.0, doubleResult1, doubleResult2;
    doubleResult1 = 1/x;
    doubleResult2 = y/x;

    //should return NaN and INF
    std::cout << doubleResult1 << ", " << doubleResult2 << std::endl;

//    //returns an error from the compiler because INF cannot be represented by integer
//    long m=0, n=0, intResult1, intResult2;
//    intResult1 = 1/m;
//    intResult2=m/n;
//
//    std::cout << intResult1 << ", " << intResult2 << std::endl;

    
    //Hacker Practice 2.3
    isPositiveZero(1.0);
    isPositiveZero(-1.0);
    isPositiveZero(__DBL_MAX__);
    isPositiveZero(-1.0*__DBL_MAX__);
    isPositiveZero(__DBL_MIN__);
    isPositiveZero(-1.0*__DBL_MIN__);
    float INF = std::numeric_limits<float>::infinity();
    isPositiveZero(INF);
    isPositiveZero(-1.0*INF);
    isPositiveZero(1.0/0.0);
    isPositiveZero(-1.0/0.0);
    isPositiveZero(+0.0);
    isPositiveZero(-0.0);
    std::cout << std::endl;
    
    isNegativeZero(1.0);
    isNegativeZero(-1.0);
    isNegativeZero(__DBL_MAX__);
    isNegativeZero(-1.0*__DBL_MAX__);
    isNegativeZero(__DBL_MIN__);
    isNegativeZero(-1.0*__DBL_MIN__);
    isNegativeZero(INF);
    isNegativeZero(-1.0*INF);
    isNegativeZero(1.0/0.0);
    isNegativeZero(-1.0/0.0);
    isNegativeZero(+0.0);
    isNegativeZero(-0.0);
    std::cout << std::endl;
    
    
    //Hacker Practice 2.4
    //soft landing of a flowing point number
    double a = 1.234567890123456;
    int i = 1;

    a *= pow(10,-307);

    for (i=1; i<20; i++) {
        a /= 10.0;
        std::cout << std::setprecision(16) << a << std::endl;
    }

    //another approach to show the percentage change between the previous
    //and new point precision error as we approach underflow
    double af = 1.234567890123456;
    af *= pow(10,-307);
    for (i=1; i<20; i++){
        double af_new = af/10.0;
        double diff = (af - (af_new*10))/(af);
        std::cout << " " << std::setprecision(32) << diff << std::endl;
        af = af_new;
    }
    
    
    
    return 0;
}
