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

#ifndef Level_HPP_INCLUDED
#define Level_HPP_INCLUDED

/*!
 * \file Level.hpp
 * \brief Level class header
 * \version 1.0
 */


#include <string>
#include <vector>

namespace sg {

    class Decor;
    class DynamicObject;
    class StaticObject;
    class Area;

    /*!
    *   \class Level
    *   \brief Some Level of the game
    */
    class Level {

        friend class LevelLoader;

    public :


        /*!
            \brief Build an empty Level, with nothing...
        */
        Level();

        ~Level();

        /*!
            \brief Build the Level and load the given file

            \see load(const std::string &filePath);
        */
        Level(const std::string &filePath);


        /*!
            \brief Load the Level from a file

            \param filePath Name of the Level file, with full path

            \warning This method will load the resource associated to the Level, so it can take a few time !
        */
        void load(const std::string &filePath);


        /*!
            \brief Clear the Level and set default value for attributs
        */
        void clear();


        /*!
            \brief Get the Level name

            \return Level name
        */
        const std::string& getName() const;


        /*!
            \brief Get the Level height

            \return Level height
        */
        int getHeight() const;


        /*!
            \brief Get the Level width

            \return Level width
        */
        int getWidth() const;

        /*!
            \brief Is the Level loaded ?

            \return True if the Level is loaded, false otherwise
        */
        bool isLoaded() const;


        /*!
            \brief Update objects on level
        */
        void update();


    protected :

        bool m_isLoaded;                            //!< Level is loaded ?

        std::string m_name;                         //!< Name of the Level

        int m_height;                               //!< Height of the Level

        int m_width;                                //!< Width of the Level

        std::vector<StaticObject *> m_staticObjects;//!< Level statics but physicals elements

        std::vector<DynamicObject *> m_vDynamics;   //!< Level dynamics elements

        std::vector<Decor *> m_vDecors;             //!< Level decorations

        std::vector<Area *> m_vAreas;               //!< Level areas
    };

}

#endif // Level_HPP_INCLUDED
