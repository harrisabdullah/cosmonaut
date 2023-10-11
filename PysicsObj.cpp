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

void PhysicsObj::applyElasticCollision(PhysicsObj *other) {
    double distance = position.distanceTo(other->position);
    if (distance > radius + other->radius){
        return;
    }
    // applying simple collision
    double intersect = radius+other->radius - distance;
    Vect2D translation = (other->position.normalVectTo(position, distance) * intersect) / 2;
    position += translation;
    other->position += -translation;

    // applying elastic collision
    Vect2D relativeVelocity = velocity - other->velocity;
    double relativeVelocityMag = relativeVelocity.mag();
    Vect2D CollisionDirection = relativeVelocity.normalise();

    Vect2D othersDirection = position.normalVectTo(other->position, distance);
    double otherAngle = CollisionDirection.angleBetween(othersDirection);

    if (otherAngle == 0){
        other->velocity = velocity;
        velocity = {.x=0, .y=0};
        return;
    }

    double thisAngle = M_PI/2 - otherAngle;

    double cosCotSin = cos(otherAngle)+sin(otherAngle)*(1/tan(thisAngle));
    double otherVelocityMag = relativeVelocityMag / cosCotSin;
    double thisVelocityMag = (relativeVelocityMag*sin(otherAngle)*(1/sin(thisAngle))) / cosCotSin;

    double thisTrueAngle = position.y > other->position.y? thisAngle : 2*M_PI-thisAngle;
    double otherTrueAngle = position.y > other->position.y? 2*M_PI-otherAngle : otherAngle;

    velocity = CollisionDirection.rotate(thisTrueAngle)*thisVelocityMag + other->velocity;
    other->velocity += CollisionDirection.rotate(otherTrueAngle)*otherVelocityMag;
}

void PhysicsObj::draw(SDL_Renderer *renderer) {
    int intRadius = static_cast<int>(radius);
    int intPosX = static_cast<int>(position.x);
    int intPosY = static_cast<int>(position.y);

    for (int x = intPosX-intRadius; x < intPosX+intRadius; x++){
        for (int y = intPosY-intRadius; y < intPosY+intRadius; y++){
            Vect2D pos = {.x=static_cast<double>(x), .y=static_cast<double>(y)};
            if (position.distanceTo(pos) < radius) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}

