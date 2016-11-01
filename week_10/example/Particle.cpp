//
//  Particle.cpp
//  particleSystem
//
//  Created by peterobbin on 10/30/16.
//
//

#include "Particle.hpp"
// using the constructor to initialize all the variables
Particle::Particle(ofVec2f position)
:mPosition(position)
, mVelocity( ofRandom(-2.f, 2.f), ofRandom(-2.f, 2.f))
, mAcceleration(ofVec2f(0))
, mLifeSpan(255.f)
{

}
//-------------------------------------
void Particle::resetForces()
{
    // reset the acceleration
    mAcceleration *= 0;
}
//-------------------------------------
void Particle::applyForce(ofVec2f force)
{
    // adding for to acceleration
    mAcceleration += force;
}
//-------------------------------------
void Particle::update(float multiplier)
{
    // apply accelearation to velocity
    mVelocity += mAcceleration;
    mPosition += mVelocity * multiplier;
    
    // decreasing the particle life
    if (mLifeSpan > 0){
        mLifeSpan -= 2.f;
    }
    
}
//-------------------------------------
void Particle::draw()
{
    if( mLifeSpan > 100 ){
        // new born partilce will be brighter
        ofSetColor(mLifeSpan);
    }else if( mLifeSpan <= 100 ){
        // do some sparkle!
        ofSetColor(ofRandom(0, 255));
    };
    
    // closer particle is smaller
    ofDrawCircle(mPosition, 3.f * ofMap(mLifeSpan, 0, 255.f, 0, 1.f));
    
}
