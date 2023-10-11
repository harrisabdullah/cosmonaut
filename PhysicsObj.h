//
// Created by Harris on 09/10/2023.
//

#ifndef COSMONAUT_PHYSICSOBJ_H
#define COSMONAUT_PHYSICSOBJ_H

#include "geometry/Vect2D.h"

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
    void applyElasticCollision(PhysicsObj *other);
};


#endif //COSMONAUT_PHYSICSOBJ_H
