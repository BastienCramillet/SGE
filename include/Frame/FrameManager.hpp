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

#ifndef FRAME_MANAGER_HPP_INCLUDED
#define FRAME_MANAGER_HPP_INCLUDED

/*!
*   \file
*   \brief
*   \version 0.1
*/

#include <string>
#include <vector>

namespace sg
{

    class Frame;


    class FrameManager
    {

        public :

            FrameManager();

            ~FrameManager();

            /**
              Add some frame into the frame manager
            */
            int addFrame(Frame *frame);

            /**
              Unload some frame. It won't change ID's of previous loaded frames
            */
            void unloadFrame(int frameID);


        protected :


        private :

            /**
                The managed frames
            */
            std::vector<Frame *> m_frames;

    };
} // namespace sg
#endif // FRAME_MANAGER_HPP_INCLUDED
