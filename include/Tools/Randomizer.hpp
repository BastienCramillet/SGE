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


#ifndef SG_RANDOMIZER_HPP
#define SG_RANDOMIZER_HPP



namespace sg
{

/**
    \class
    \brief This class provide random tools. It's based on SFML1 randomizer

    \sa https://github.com/LaurentGomila/SFML/blob/sfml1/include/SFML/System/Randomizer.hpp
*/
class Randomizer
{
public :

    ////////////////////////////////////////////////////////////
    /// Set the seed for the generator. Using a known seed
    /// allows you to reproduce the same sequence of random number
    ///
    /// \param Seed : Number to use as the seed
    ///
    ////////////////////////////////////////////////////////////
    static void setSeed(unsigned int seed);

    ////////////////////////////////////////////////////////////
    /// Get the seed used to generate random numbers the generator.
    ///
    /// \return Current seed
    ///
    ////////////////////////////////////////////////////////////
    static unsigned int getSeed();

    ////////////////////////////////////////////////////////////
    /// Get a random float number in a given range
    ///
    /// \return Start : Start of the range
    /// \return End :   End of the range
    ///
    /// \return Random number in [Begin, End]
    ///
    ////////////////////////////////////////////////////////////
    static float random(float begin, float end);

    ////////////////////////////////////////////////////////////
    /// Get a random integer number in a given range
    ///
    /// \return Start : Start of the range
    /// \return End :   End of the range
    ///
    /// \return Random number in [Begin, End]
    ///
    ////////////////////////////////////////////////////////////
    static int random(int begin, int end);

private :

    ////////////////////////////////////////////////////////////
    // Static member variables
    ////////////////////////////////////////////////////////////
    static unsigned int ourSeed;
};

} // namespace sg


#endif // SG_RANDOMIZER_HPP
