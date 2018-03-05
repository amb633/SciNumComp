//
//  main.cpp
//  hacker44_thru_45
//
//  Created by Ariana Bruno on 3/4/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <numeric> // for inner producr

using namespace std;


double det( vector<vector<double>>* A){
    return ((*A)[0][0]*(*A)[1][1]) - ((*A)[0][1]*(*A)[1][0]);
}

void inv( vector<vector<double>>* A, vector<vector<double>>* A_inv, double det_A){
    (*A_inv)[0][0] = (1.0/det_A)*((*A)[1][1]);
    (*A_inv)[1][1] = (1.0/det_A)*((*A)[0][0]);
    (*A_inv)[0][1] = (1.0/det_A)*(-1.0*(*A)[1][0]);
    (*A_inv)[1][0] = (1.0/det_A)*(-1.0*(*A)[0][1]);
}

double productAxFM( vector< vector<double>>* input, vector<double>* x, vector<double>* b){
    if((*input)[0].size() == (*x).size()){
        int rows = (*input).size();
        for( int i=0; i<rows; i++ ){
            double product = inner_product((*input)[i].begin(), (*input)[i].end(), (*x).begin(), 0);
            (*b).push_back(product);
        }
        return 0;
    }
    return 1;
}

double residual_norm( vector<double>* solved, vector<double>* given,vector<double>* result ){
    transform(solved->begin(), solved->end(), given->begin(), result->begin(), minus<int>());
    double sum = 0.0;
    for( int i = 0; i<result->size(); i++){
        sum = sum + ((*result)[i]*(*result)[i]);
    }
    sum = sqrt(sum);
    return sum;
}


int main(int argc, const char * argv[]) {
    
//    Hacker practice 4.3
    vector<vector<double>> input = {{100, 99}, {99, 98}};
    vector<double> output = {199, 197};
    
    vector<vector<double>> input_inv = input;
    vector<double> result;
    
    double det_input = det(&input);
    inv(&input, &input_inv, det_input);
    double check = productAxFM(&input_inv, &output, &result);
    for( int i = 0; i< result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    
    for (int i =2; i<=9; i++){
        double e = pow(10.0, -i);
        vector<vector<double>> input = {{100, 99}, {99, 98.01-e}};
        vector<vector<double>> input_inv = input;
        vector<double> result;
        double det_input = det(&input);
        inv(&input, &input_inv, det_input);
        double check = productAxFM(&input_inv, &output, &result);
        cout << "this is x,y : " << endl;
        for( int i = 0; i< result.size(); i++){
            cout << result[i] << " ";
        }
        cout << endl;
        
        vector<double> output_solver;
        double check1 = productAxFM(&input, &result, &output_solver);
        cout << "this is the solver output for b: " << endl;
        for( int i = 0; i< output_solver.size(); i++){
            cout << output_solver[i] << " ";
        }
        cout << endl;
        vector<double> diff;
        diff.resize(output.size());
        double difference = residual_norm(&output_solver, &output, &diff);
        cout << "this is the difference between outputs: " << difference <<  endl;
        cout << endl;
        
        
    }
    
    
    
    return 0;
}
