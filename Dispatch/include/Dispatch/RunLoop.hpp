/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2020 Jean-David Gadina - www.xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      RunLoop.hpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#ifndef DISPATCH_RUN_LOOP_HPP
#define DISPATCH_RUN_LOOP_HPP

#include <memory>
#include <algorithm>
#include <Dispatch/Timer.hpp>
#include <Dispatch/Action.hpp>

namespace Dispatch
{
    class RunLoop
    {
        public:
            
            enum class RunStatus: int
            {
                DoneRunning,
                AlreadyRunning
            };
            
            RunLoop();
            ~RunLoop();
            
            RunLoop( const RunLoop & )              = delete;
            RunLoop( RunLoop && )                   = delete;
            RunLoop & operator =( const RunLoop & ) = delete;
            RunLoop & operator =( RunLoop && )      = delete;
            
            RunStatus run();
            void      stop();
            void      waitUntilStopped();
            
            void addTimer(    const Timer & timer );
            void removeTimer( const Timer & timer );
            
        private:
            
            class IMPL;
            
            std::unique_ptr< IMPL > impl;
    };
}

#endif /* DISPATCH_RUN_LOOP_HPP */
