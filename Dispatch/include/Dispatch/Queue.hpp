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
 * @header      Queue.hpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#ifndef DISPATCH_QUEUE_HPP
#define DISPATCH_QUEUE_HPP

#include <memory>
#include <algorithm>
#include <string>
#include <Dispatch/Thread.hpp>
#include <Dispatch/Action.hpp>
#include <Dispatch/Interval.hpp>
#include <Dispatch/Timer.hpp>

namespace Dispatch
{
    class Queue
    {
        public:
            
            enum class Kind: int
            {
                Serial,
                Concurrent
            };
            
            static Queue & Global( Thread::Priority priority );
            static Queue & Low();
            static Queue & Normal();
            static Queue & High();
            
            Queue( const std::string & label, Kind kind, Thread::Priority priority = Thread::Priority::Normal );
            ~Queue();
            
            Queue( const Queue & )              = delete;
            Queue( Queue && )                   = delete;
            Queue & operator =( const Queue & ) = delete;
            Queue & operator =( Queue && )      = delete;
            
            bool operator ==( const Queue & o ) const;
            bool operator !=( const Queue & o ) const;
            
            UUID             uuid()     const;
            std::string      label()    const;
            Kind             kind()     const;
            Thread::Priority priority() const;
            
            void sync(       const Action & action );
            void async(      const Action & action );
            void asyncAfter( const Action & action, const Interval & interval );
            void schedule(   const Timer & timer );
            void unschedule( const Timer & timer );
            
        private:
            
            class IMPL;
            
            std::unique_ptr< IMPL > impl;
    };
}

#endif /* DISPATCH_QUEUE_HPP */
