/** 
 * @file tanksim.cc
 * @brief Main file for the tank simulation program.
 * @author Rashad Khan
 * @date 2024-06-10
 */
#include <iostream>
#include "tanksim.h"


int main(){
    Tank myTank(0.0, 0.0, 0.0, 0.0, 5, "Tiger");
    Tank Player2(10.0, 0.0, 0.0, 90.0, 8, "Abrams");

    myTank.printStatus();
    Player2.printStatus();
    return 0;
}

