//
//  main.cpp
//  HackerPractice7
//
//  Created by Ariana Bruno on 4/23/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include "hackpractice_Functions.hpp"

int main(int argc, const char * argv[]) {
    vector<vector<double>> A1 = {{-2, 1, 0, 0}, {1, -2, 1, 0}, {0, 1, -2, 1}, {0, 0, 1, -2}};
    vector<vector<double>> A2 = {{-2, 1, 0, 0}, {1, -2, 1, 0}, {0, 1, -2, 1}, {0, 0, 1, -1}};
    vector<double> b = {-1, 0, 0, 0};
    
    cout << endl <<  "Hacker Practice 7.1 for psi(x=0) = 1 and psi(x=L) = 0" << endl;
    jacobianSolver(&A1, &b);
    
    cout << endl << "Hacker Practice 7.1 for psi(x=0) = 1 and psi(x=L) => psi_N-1 = psi_N" << endl;
    jacobianSolver(&A2, &b);
    
    return 0;
}
