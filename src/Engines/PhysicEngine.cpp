/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
*
* Copyright (c) 2012 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
*    1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
*
*    2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
*
*    3. This notice may not be removed or altered from any source
*   distribution.
*
*-----------------------------------------------------------------------------*/

/*!
*   \file PhysicEngine.cpp
*   \brief The physic engine source
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Engines/PhysicEngine.hpp>
#include <Constants.hpp>
#include "Box2D.h"

#include <Core/DebugNew.hpp>

#include <Tools/Log.hpp>


namespace sg
{

    PhysicEngine::PhysicEngine () : Thread()
    {
        init();
    }

    PhysicEngine::~PhysicEngine ()
    {
        clear();
    }

    void PhysicEngine::clear ()
    {
        if (m_world != 0)
        {
            delete m_world;
            m_world = 0;
        }
    }

    void PhysicEngine::init()
    {
        b2Vec2 gravity(0.0f, 9.8f);                     // Gravity of the world
        m_world = new b2World(gravity);       // v2.2.1
        m_world->SetAllowSleeping(true);   // Stop to calculate movement for non-moving objects
        m_velocityIterations = 8;     // If your machine is powerfull enough, this is the best configuration
        m_positionIterations = 3;
        m_frequency = sf::microseconds(10000);
        m_running = true;

    }

    void PhysicEngine::update ()
    {
        m_world->Step(m_frequency.asSeconds(), m_velocityIterations, m_positionIterations);
        m_world->ClearForces();
    }

    void PhysicEngine::run ()
    {
        Log::d("PhysicEngine") << "Start running";
        sf::Clock timer;
        while (m_running)
        {
            if (timer.getElapsedTime().asMicroseconds() < m_frequency.asMicroseconds())
                sf::sleep(m_frequency - timer.getElapsedTime());

            timer.restart();
            update();
        }

    }

    void PhysicEngine::setRunning(bool running)
    {
        m_running = running;
    }



    b2Body* PhysicEngine::createStaticBox(float xPosition, float yPosition, float xSize, float ySize,
                                          float density, float friction, float restitution)
    {
        // Creation of a static rectangle
        b2BodyDef bodyDef;
        bodyDef.position.Set(xPosition / BOX2D_SIZE_REDUCTION,
                             yPosition / BOX2D_SIZE_REDUCTION);
        bodyDef.angle = 0.f;
        b2Body* body = m_world->CreateBody(&bodyDef);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox((xSize / (BOX2D_SIZE_REDUCTION * 2.f)) - 0.01,
                            (ySize / (BOX2D_SIZE_REDUCTION * 2.f)) - 0.01);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.restitution = restitution;

        body->CreateFixture(&fixtureDef);

        return body;
    }

    b2Body* PhysicEngine::createDynamicBox(float xPosition, float yPosition, float xSize, float ySize,
                                          float density, float friction, float restitution)
    {
        // Creation of a dynamic rectangle
        b2BodyDef bodyDef;                              // Declaration of the body
        bodyDef.type = b2_dynamicBody;                  // Set the body as a dynamic one
        bodyDef.position.Set(xPosition / BOX2D_SIZE_REDUCTION,
                             yPosition / BOX2D_SIZE_REDUCTION);        // Set the body position
        bodyDef.angle = 0.f;                            // Set the body angle
        b2Body* body = m_world->CreateBody(&bodyDef); // We ask to the body factory to create it

        b2PolygonShape dynamicBox;                      // Declaration of the shape
        dynamicBox.SetAsBox((xSize / (BOX2D_SIZE_REDUCTION * 2.f)) - 0.01,
                            (ySize / (BOX2D_SIZE_REDUCTION * 2.f)) - 0.01);    // Set the size and the shape as a box

        b2FixtureDef fixtureDef;                        // We create a new fixture for the body
        fixtureDef.shape = &dynamicBox;                 // We attach the shape of the body to the fixture
        fixtureDef.density = density;                      // We set the density of the shape
        fixtureDef.friction = friction;                     // We set the friction of the shape
        fixtureDef.restitution = restitution;                  // We set the restitution of the shape

        body->CreateFixture(&fixtureDef);               // We link the fixture to the body

        return body;
    }

    b2Body* PhysicEngine::createStaticCircle (float xPosition, float yPosition, float radius,
                                          float density, float friction, float restitution)
    {
        b2BodyDef bodyDef;
        bodyDef.position.Set(xPosition / BOX2D_SIZE_REDUCTION,
                             yPosition / BOX2D_SIZE_REDUCTION);
        bodyDef.angle = 0.f;
        b2Body* body = m_world->CreateBody(&bodyDef);

        b2CircleShape dynamicCircle;
        dynamicCircle.m_radius = radius / BOX2D_SIZE_REDUCTION;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicCircle;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.restitution = restitution;

        body->CreateFixture(&fixtureDef);


        return body;
    }


    b2Body* PhysicEngine::createDynamicCircle (float xPosition, float yPosition, float radius,
                                          float density, float friction, float restitution)
    {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(xPosition / BOX2D_SIZE_REDUCTION,
                             yPosition / BOX2D_SIZE_REDUCTION);
        bodyDef.angle = 0.f;
        b2Body* body = m_world->CreateBody(&bodyDef);

        b2CircleShape dynamicCircle;
        dynamicCircle.m_radius = radius / BOX2D_SIZE_REDUCTION;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicCircle;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.restitution = restitution;

        body->CreateFixture(&fixtureDef);


        return body;
    }

    b2Body* PhysicEngine::createStaticEdge (float xFirstPosition, float yFirstPosition, float xSecondPosition, float ySecondPosition,
                                          float density, float friction, float restitution)
    {

    }

    b2Body* PhysicEngine::createStaticChainShape (std::vector<std::pair<float,float> > vpCoord,
                                          float density, float friction, float restitution)
    {
        int size = vpCoord.size();
        b2Vec2 vCoord[size];
        for (unsigned short int i = 0; i < size; ++i)
        {
            vCoord[i].Set(vpCoord[i].first / BOX2D_SIZE_REDUCTION,
                          vpCoord[i].second / BOX2D_SIZE_REDUCTION);
        }

        b2BodyDef bodyDef;
        bodyDef.angle = 0.f;
        b2Body* body = m_world->CreateBody(&bodyDef);

        b2ChainShape staticChain;
        staticChain.CreateChain(vCoord, size);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &staticChain;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.restitution = restitution;

        body->CreateFixture(&fixtureDef);

        return body;
    }

    b2Body* PhysicEngine::createStaticPolygon()
    {

    }

    b2Body* PhysicEngine::createDynamicPolygon()
    {

    }

} // namespace sg
