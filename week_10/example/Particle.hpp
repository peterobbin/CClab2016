//
//  Particle.hpp
//  particleSystem
//
//  Created by peterobbin on 10/30/16.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    // creating a constructor
    Particle(ofVec2f pos);
    
    void resetForces();
    void applyForce(ofVec2f force);
    void update(float multiplier);
    void draw();
    
    ofVec2f mPosition, mVelocity, mAcceleration;
    float mLifeSpan;
};
