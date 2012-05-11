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

#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

/*!
 * \file Map.hpp
 * \brief Map class header
 * \version 1.0
 */


#include <string>


namespace sg {

    /*!
    *   \class Map
    *   \brief Some map of the game
    */
    class Map {

    public :


        /*!
            \brief Build an empty map, with nothing...
        */
        Map();


        /*!
            \brief Build the map and load the given file

            \see load(const std::string &filePath);
        */
        Map(const std::string &filePath);


        /*!
            \brief Load the map from a file

            \param filePath Name of the map file, with full path

            \warning This method will load the resource associated to the map, so it can take a few time !
        */
        void load(const std::string &filePath);


        /*!
            \brief Clear the map and set default value for attributs
        */
        void clear();


        /*!
            \brief Get the map name

            \return Map name
        */
        const std::string& getName() const;


        /*!
            \brief Get the map height

            \return Map height
        */
        int getHeight() const;


        /*!
            \brief Get the map width

            \return Map width
        */
        int getWidth() const;

        /*!
            \brief Is the map loaded ?

            \return True if the map is loaded, false otherwise
        */
        bool isLoaded() const;


    protected :

        bool m_isLoaded;        //!< Map is loaded ?

        std::string m_name;     //!< Name of the map

        int m_height;           //!< Height of the map

        int m_width;            //!< Width of the map

    };

}

#endif // MAP_HPP_INCLUDED
