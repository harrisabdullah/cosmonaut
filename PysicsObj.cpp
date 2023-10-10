//
// Created by Harris on 09/10/2023.
//

#include "PhysicsObj.h"

double const G = 6.67e-11;

void PhysicsObj::applyForce(Vect2D force) {
    Vect2D acceleration = force / mass;
    velocity += acceleration * timeInterval;
}

void PhysicsObj::updatePos() {
    position += velocity * timeInterval;
}

void PhysicsObj::applyGravity(PhysicsObj *other) {
    double distance = position.distanceTo(other->position);
    double gravityForceMag = (G*mass*other->mass) / distance*distance;

    Vect2D vectBetween = position.normalVectTo(other->position, distance);
    Vect2D gravityForce = vectBetween * gravityForceMag;

    applyForce(gravityForce);
    other->applyForce(-gravityForce);
}

