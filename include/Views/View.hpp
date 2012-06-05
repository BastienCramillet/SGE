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

#ifndef VIEW_HPP_INCLUDED
#define VIEW_HPP_INCLUDED

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/View.hpp>

#include "Frame/Frame.hpp"

namespace sg {

    /*!
    *   \class View
    *   \brief A view
    */
    class View : public sf::View {

    public :

        /**
            \brief Create a view with a focuse on center and a size of size
        */
        View(const sf::Vector2f &center, const sf::Vector2f &size);

        virtual ~View();


        /**
            \brief Initialize the view (computes...)

            If there is something to compute before adding a view in a frame, it's here.

            This method will be call once time
        */
        virtual void initialize() {
        }


        /**
            If there is some automatic action in the child view, this method should be override

            There is no stuff here
        */
        virtual void update() {
        }


        /**
            \brief Is this view initialized
        */
        bool isInitialized() const;


    private :

        /**
            \brief Mark initialization as done

            Access reserved to Frame
        */
        void markAsInitialized();

        friend void Frame::addView(const std::string &, View *);


        bool m_isInitialized;

    };

}

#endif
