//
//  main.cpp
//  hackerpractice_46
//
//  Created by Ariana Bruno on 3/6/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include "hackpractice_Functions.hpp"



int main(int argc, const char * argv[]) {
    vector<vector<double>> A = {{-4.0, 1.0, 0.0, 0.0, 1.0}, {4.0, -4.0, 1.0, 0.0, 0.0}, { 0.0, 1.0, -4.0, 1.0, 0.0}, {0.0, 0.0, 1.0, -4.0, 1.0}, {1.0, 0.0, 0.0, 1.0, -4.0}};
    vector<double> b = {1.0, 0.0, 0.0, 0.0 ,0.0};
    
    jacobianSolver(&A, &b);
    
    SORSolver(&A, &b);
    
    
    
    return 0;
}
