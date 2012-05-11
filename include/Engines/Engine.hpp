/*------------------------------------------------------------------------------
*
* SE - Simple Engine
*
* Copyright (c) 2010-2011 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
*                         Xavier Michel (Saffir)(xavier.michel.mx440@gmail.com)
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

#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

/*!
*   \file Engine.hpp
*   \brief Engines mother class header
*   \version 1.0
*/

// includes

namespace sg
{

    /*!
    *   \class Engine
    *   \brief Engine mother class
    */

    class Engine
    {
        public :

            /*!
            *   \brief Engine class constructor
            *
            *   \param game Parent object
            */
            Engine (Game* game);

            /*!
            *   \biref Engine class destructor
            */
            virtual ~Engine ();

            /*!
            *   \brief Add an event to the engine event queue
            *
            *   \param event The engine event to add
            */
            void pushEvent (EngineEvent& event){
                m_eventsQueue.push(event);
            }

            /*!
            *   \brief Treat the event queue
            */
            void processQueue ()
            {
                while (! m_eventsQueue.empty())
                {
                    EnginEvent event = m_eventsQueue.front();
                    m_eventsQueue.pop();

                    processEvent(event);
                }
            }

            /*!
            *  \brief Own engine treatment
            */
            virtual void frame() = 0;

        protected:

            /*!
            *   \brief Own treatment of an event by the engine
            *
            *   \param event Event to treat
            */
            virtual void processEvent(EngineEvent& event) = 0;

            Game                    *m_pParent;     //!< Pointer to the parent object
            std::queue<EngineEvent> m_eventsQueue;  //!< Event queue to treat


    };

} // namespace sg

#endif // ENGINE_HPP_INCLUDED
