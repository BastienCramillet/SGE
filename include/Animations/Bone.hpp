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

#ifndef BONE_HPP_INCLUDED
#define BONE_HPP_INCLUDED

namespace sg
{
    class Node;
    class Bone
    {
        public :

            Bone();

            Bone(sg::Node* parentNode, float angle, float scale);

            ~Bone();

            void rotate(float angle);

            void computeChildPosition();


        private :

            float m_angle;  //!< Angle of the bone, in radians
            float m_length; //!< Length of the bone
            sg::Node* m_pParent;
            sg::Node* m_pChild;
    };
}



#endif // BONE_HPP_INCLUDED
