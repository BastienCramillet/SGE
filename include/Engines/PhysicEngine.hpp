/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
*
* Copyright (c) 2012 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
*                    Xavier Michel (Saffir)(xavier.michel.mx440@gmail.com)
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
*   \file PhysicEngine.hpp
*   \version 0.1
*/

#ifndef PHYSICENGINE_HPP_INCLUDED
#define PHYSICENGINE_HPP_INCLUDED

#include <Core/Singleton.hpp>
#include <Core/Thread.hpp>
#include <Engines/Engine.hpp>

#include <vector>
#include <algorithm>

class b2Body;
class b2World;

namespace sg
{
    class PhysicEngine : public Singleton<PhysicEngine>, public Thread, public Engine
    {
        friend class Singleton<PhysicEngine>;

        public :

            void init();

            void clear();

            void update();

            void run();

            void setRunning(bool running);

            /*!
            *   \brief Create a physical static box
            *
            *   \param xPosition The x position of the box
            *   \param yPosition The y position of the box
            *   \param xSize The width of the box
            *   \param ySize The height of the box
            *
            *   \return A pointer to a b2Body object
            */
            b2Body* createStaticBox(float xPosition, float yPosition, float xSize, float ySize,
                                    float density = 1.0, float friction = 0.3, float restitution = 0.3);

            b2Body* createDynamicBox(float xPosition, float yPosition, float xSize, float ySize,
                                     float density = 1.0, float friction = 0.3, float restitution = 0.3);

            b2Body* createStaticCircle(float xPosition, float yPosition, float radius,
                                       float density = 1.0, float friction = 0.3, float restitution = 0.3);

            b2Body* createDynamicCircle(float xPosition, float yPosition, float radius,
                                        float density = 1.0, float friction = 0.3, float restitution = 0.3);

            b2Body* createStaticEdge (float xFirstPosition, float yFirstPosition, float xSecondPosition, float ySecondPosition,
                                      float density = 1.0, float friction = 0.3, float restitution = 0.3);

            b2Body* createStaticChainShape (std::vector<std::pair<float,float> > vpCoord,
                                            float density = 1.0, float friction = 0.3, float restitution = 0.3);

            b2Body* createStaticPolygon();

            b2Body* createDynamicPolygon();

            void move (const std::string& id, float xMove, float yMove);

        private :

            PhysicEngine();
            ~PhysicEngine();
            void treatMessage (EngineMessage* message);

            b2World* m_world;
            std::map<std::string, b2Body*> m_mBody;
            int m_velocityIterations;
            int m_positionIterations;

            sf::Time m_frequency;
            bool m_running;


    };
}

#endif // PHYSICENGINE_HPP_INCLUDED
