//
// Created by Harris on 10/10/2023.
//

#ifndef COSMONAUT_VECT2D_H
#define COSMONAUT_VECT2D_H

#include <cmath>
#include <iostream>

struct Vect2D {
    double x;
    double y;

    Vect2D&operator+=(const Vect2D& other){
        x += other.x;
        y += other.y;
        return *this;
    }

    Vect2D operator/(double num) const{
        return {.x=x/num, .y=y/num};
    }

    Vect2D operator*(double num) const{
        return {.x=x*num, .y=y*num};
    }

    Vect2D operator-() const{
        return {.x=-x, .y=-y};
    }

    Vect2D operator-(Vect2D other) const {
        return {.x=x-other.x, .y=y-other.y};
    }

    Vect2D operator+(Vect2D other) const {
        return {.x=x+other.x, .y=y+other.y};
    }

    double distanceTo(Vect2D other){
        return sqrt((x-other.x)*(x-other.x) + (y-other.y)*(y-other.y));
    }

    Vect2D normalVectTo(Vect2D other){
        double distance = distanceTo(other);
        Vect2D vectBetween = {.x=other.x-x, .y=other.y-y};
        return vectBetween / distance;
    }

    Vect2D normalVectTo(Vect2D other, double distance) const{
        Vect2D vectBetween = {.x=other.x-x, .y=other.y-y};
        return vectBetween / distance;
    }

    double mag(){
        return sqrt(x*x + y*y);
    }

    Vect2D normalise(){
        double magnitude = mag();
        return {.x=x/magnitude, .y=y/magnitude};
    }

    double dotProd(Vect2D other) {
        return x * other.x + y * other.y;
    }

    double angleBetween(Vect2D other){
        double temp = dotProd(other) / (mag() * other.mag());
        if (temp >= 1){
            return 0;
        }

        if (temp <= -1){
            return 0;
        }

        return acos(temp);
    }

    Vect2D rotate(double theta){
        return {.x= x*cos(theta) - y*sin(theta), .y=x*sin(theta) + y*cos(theta)};
    }
};


#endif //COSMONAUT_VECT2D_H
