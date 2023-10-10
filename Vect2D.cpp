//
// Created by Harris on 09/10/2023.
//

#include <cmath>

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
};