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
*   \file FrameManager.hpp
*   \author Xavier
*   \version 0.1
*/

#include <vector>

namespace sg
{

    class Frame;

    /**
        \class FrameManger
        \brief This manager manage a list of frame

        Example :
        \code

            sg::FrameManager frameManager;

            sg::GameFrame *gameFrame = new sg::GameFrame();
            sg::GameFrame *loadingFrame = new LoadingFrame(); // just imagine

            int loadingFrame = frameManager.addFrame(loadingFrame);
            int gameFrameID  = frameManager.addFrame(gameFrame);

            // when frameManager is destroyed, all attached frames are destroyed too

        \endcode
    */
    class FrameManager
    {

        public :

            /**
                \brief Create a manager
            */
            FrameManager();

            /**
                \brief Kill this manager
            */
            ~FrameManager();

            /**
                \brief Add some frame into the frame manager
            */
            int addFrame(Frame *frame);

            /**
                \brief Unload some frame. It won't change ID's of previous loaded frames
            */
            void unloadFrame(int frameID);

            /**
                \brief Get a frame from the frame id
            */
            Frame* getFrame(int frameID);


        private :

            /**
                \brief Does the frame at the given index is valid ?
            */
            bool frameExists(unsigned int index);


            std::vector<Frame *> m_frames;  //!< The managed frames

    };
} // namespace sg
#endif // FRAME_MANAGER_HPP_INCLUDED
