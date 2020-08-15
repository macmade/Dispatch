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
 * @file        Queue.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <Dispatch/Queue.hpp>
#include <Dispatch/Loop.hpp>
#include <thread>
#include <condition_variable>

#ifdef __APPLE__
#include <pthread.h>
#endif

namespace Dispatch
{
    class Queue::IMPL
    {
        public:
            
            IMPL( const std::string & label, Kind kind, Priority priority );
            ~IMPL();
            
            void _run();
            
            std::string _label;
            Kind        _kind;
            Priority    _priority;
            Loop        _loop;
    };
    
    Queue::Queue( const std::string & label, Kind kind, Priority priority ):
        impl( std::make_unique< IMPL >( label, kind, priority ) )
    {}
    
    Queue::~Queue()
    {}
    
    std::string Queue::label() const
    {
        return this->impl->_label;
    }
    
    Queue::Kind Queue::kind() const
    {
        return this->impl->_kind;
    }
    
    Queue::Priority Queue::priority() const
    {
        return this->impl->_priority;
    }
    
    void Queue::sync( const Action & action )
    {
        ( void )action;
    }
    
    void Queue::async( const Action & action )
    {
        ( void )action;
    }
    
    void Queue::asyncAfter( const Action & action, const Interval & interval )
    {
        ( void )action;
        ( void )interval;
    }
    
    void Queue::schedule( const Timer & timer )
    {
        ( void )timer;
    }
    
    Queue::IMPL::IMPL( const std::string & label, Kind kind, Priority priority ):
        _label(    label ),
        _kind(     kind ),
        _priority( priority )
    {
        std::thread
        (
            [ & ]()
            {
                this->_run();
            }
        )
        .detach();
    }
    
    Queue::IMPL::~IMPL()
    {}
    
    void Queue::IMPL::_run()
    {
        #ifdef __APPLE__
        pthread_setname_np( this->_label.c_str() );
        #endif
        
        this->_loop.run();
    }
}
