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

#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

/*!
*   \file
*   \brief
*   \version 0.1
*/

#include <string>
#include <map>


namespace sg
{
    class View;

    /**
      \class Frame
      \brief A frame is an abstract screen of the application
    */
    class Frame
    {
        public :


            Frame();


            virtual ~Frame();


            /**
                \brief Returns the current frame view
            */
            View* getCurrentView();


            /**
                \brief Initialize and attache some view to this Frame

                \param key
                            The view name
                \param view
                            the new view

              The added view will be automaticly managed and freed from memory
            */
            void addView(const std::string &key, View *v);


            /**
                \brief Set the current view
            */
            void setCurrentView(const std::string &key);


            /**
                \brief Update elements in the frame
            */
            virtual void update();


        protected :

            std::map<std::string, sg::View *> m_views;  //!< this frames registred views <key, view>

            View *m_view;                               //!< The current view

    };
} // namespace sg
#endif // FRAME_HPP_INCLUDED
