#ifndef PHYSICENGINE_HPP_INCLUDED
#define PHYSICENGINE_HPP_INCLUDED

#include <Core/Singleton.hpp>
#include <Core/Thread.hpp>
#include <vector>
#include <algorithm>

class b2Body;
class b2World;

namespace sg
{
    class PhysicEngine : public Singleton<PhysicEngine>, public Thread
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

        private :

            PhysicEngine();
            ~PhysicEngine();

            b2World* m_world;
            int m_velocityIterations;
            int m_positionIterations;

            sf::Time m_frequency;
            bool m_running;


    };
}

#endif // PHYSICENGINE_HPP_INCLUDED
