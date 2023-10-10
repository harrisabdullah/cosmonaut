//
// Created by Harris on 09/10/2023.
//

#ifndef COSMONAUT_PHYSICSOBJ_H
#define COSMONAUT_PHYSICSOBJ_H

#include "Vect2D.cpp"

class PhysicsObj {
public:
    Vect2D position;
    Vect2D velocity;
    double radius;
    double mass;
    double timeInterval;

    void applyForce(Vect2D force);
    void updatePos();
    void applyGravity(PhysicsObj *other);
};


#endif //COSMONAUT_PHYSICSOBJ_H
