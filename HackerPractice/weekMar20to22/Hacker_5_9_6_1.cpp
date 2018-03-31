//
//  main.cpp
//  HackerPracticeMar23
//
//  Created by Ariana Bruno on 3/23/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
//   Hacker 5_9
    for( int k = 1; k<=6; k++ ){
        int count = 0;
        int N = pow(10.0, k);
        for( int i = 0; i< N; i++){
            double x = rand()/ (RAND_MAX*1.0);
            double y = rand()/ (RAND_MAX*1.0);
            //        cout << x << endl;
            //        cout << y << endl;
            if ( ( x*x + y*y ) < 1 ){
                count++;
            }
        }
        double pi_calc = 4.0*count/N;
        cout << "For N: " << N <<", Pi = " << pi_calc << ", with error = ";
        double error = log(abs(M_PI - pi_calc));
        cout << error << endl;
    }
    
//    Hacker 6_1
    vector<double> v_vec = {};
    vector<double> p_v_vec = {};
    vector<double> F_v_vec = {};
    double lambda = 0.2;
    for (int j = 0; j<1000; j++){
        double u = rand()/(RAND_MAX*1.0);
        double v = (-1.0/lambda)*log(1-u);
        v_vec.push_back(v);
    }
    sort(v_vec.begin(), v_vec.end());
    
    for( int i =0; i < v_vec.size(); i++){
        double v = v_vec[i];
        double p_v = 0;
        if(v >= 0){
            p_v = lambda*exp(lambda*v);
        }
        p_v_vec.push_back(p_v);
        F_v_vec.push_back(1.0-exp(-lambda*v));
    }
    
    double bin = 0.5;
    double iter = 0.5;
    vector<double> bin_val = {};
    vector<double> bin_pv = {};
    vector<double> bin_Fv = {};
    
    while(bin<=10){
        double bin_pv_sum = 0.0;
        double bin_Fv_sum = 0.0;
        int count = 0;
        
        for( int k = 0; k<v_vec.size(); k++){
            double v = v_vec[k];
            if( v <= bin ){
                bin_pv_sum = bin_pv_sum+p_v_vec[k];
                bin_Fv_sum = bin_Fv_sum+F_v_vec[k];
                count++;
            } else{
                break;
            }
        }
        
        bin_val.push_back(bin);
        bin_pv.push_back(bin_pv_sum/count);
        bin_Fv.push_back(bin_Fv_sum/count);
        bin = bin + iter;
    }
    
    for( int a =0; a<bin_val.size(); a++){
        cout << "Bin: " << bin_val[a] << ", pv= " << bin_pv[a] << ", Fv= " << bin_Fv[a] << endl;
    }
    
    return 0;
}
