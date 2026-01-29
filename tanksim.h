/**
 * @file tanksim.h
 * @brief Header file for the tank simulation program.
 * @author Rashad
 * @date 2024-06-10
 */

#ifndef TANKSIM_H
#define TANKSIM_H

#include <iostream>
#include <string>

//enums and structs
enum MovementDirection { POSITIVE, NEGATIVE };
enum Axis { X_AXIS, Y_AXIS, Z_AXIS }; 
struct AngleComposite { double PITCH; double YAW;};

class Projectile;
class Tank;

/**
 * @class Tank
 * @brief Represents a tank in the simulation.
 * @author Rashad
 * @ingroup TankSim
 * @date 2024-06-10 
 */
class Tank {
public:         
    Tank();
    Tank(double x, double y, double z, double dir, int ammo, std::string name);
    void changeCoord(double distance, Axis ax, MovementDirection dir);
    ~Tank();
    std::string getStatus();
    std::string printStatus();
private:
    Projectile* ammotype; // Pointer to Projectile object
    double positionX;
    double positionY;
    double positionZ;
    std::string name;  
    struct 

    double direction; // in degrees
    int ammo;
};

// Implementation of Tank class methods
Tank::Tank() : positionX(0), positionY(0), positionZ(0), direction(0), ammo(10), name("DefaultTank") {}
Tank::Tank(double x, double y, double z, double direc, int ammoc, std::string name) : positionX(x), positionY(y), positionZ(z), direction(direc), ammo(ammoc), name(name) {}
Tank::~Tank() {}

void Tank::changeCoord(double distance, Axis ax, MovementDirection dir) {
    // Simple movement logic (not accounting for direction)
    switch(ax) {
        case X_AXIS:
            positionX += (dir == POSITIVE ? distance : -distance);
            break;
        case Y_AXIS:
            positionY += (dir == POSITIVE ? distance : -distance);
            break;
        case Z_AXIS:
            positionZ += (dir == POSITIVE ? distance : -distance);
            break;
    }

    std::cout << "Tank "<< name << " moved to (" << positionX << ", " << positionY << ", " << positionZ << ")\n";
}

std::string Tank::getStatus() {
    return "Position: (" + std::to_string(positionX) + ", " + std::to_string(positionY) + ", " + std::to_string(positionZ) + "), Direction: " + std::to_string(direction) + ", Ammo: " + std::to_string(ammo);
}

std::string Tank::printStatus() {
    std::cout << getStatus() << std::endl;
    return getStatus();
}


#endif // TANKSIM_H

