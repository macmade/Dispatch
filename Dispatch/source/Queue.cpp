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
#include <Dispatch/RunLoop.hpp>
#include <thread>
#include <mutex>
#include <map>
#include <type_traits>
#include <exception>
#include <array>
#include <condition_variable>

namespace Dispatch
{
    class Queue::IMPL
    {
        public:
            
            IMPL( const std::string & label, Kind kind, Thread::Priority priority );
            ~IMPL();
            
            void _run();
            
            UUID             _uuid;
            std::string      _label;
            Kind             _kind;
            Thread::Priority _priority;
            RunLoop          _rl;
    };
    
    Queue & Queue::Global( Thread::Priority priority )
    {
        static std::once_flag                              once;
        static std::array< std::unique_ptr< Queue >, 3 > * queues;
        
        std::call_once
        (
            once,
            [ & ]()
            {
                queues = new std::remove_pointer< decltype( queues ) >::type();
                
                queues->at( 0 ) = std::make_unique< Queue >
                (
                    "com.xs-labs.Dispatch.Queue.Global.Low",
                    Kind::Concurrent,
                    Thread::Priority::Low
                );
                
                queues->at( 1 ) = std::make_unique< Queue >
                (
                    "com.xs-labs.Dispatch.Queue.Global.Normal",
                    Kind::Concurrent,
                    Thread::Priority::Normal
                );
                
                queues->at( 2 ) = std::make_unique< Queue >
                (
                    "com.xs-labs.Dispatch.Queue.Global.High",
                    Kind::Concurrent,
                    Thread::Priority::High
                );
            }
        );
        
        if( priority == Thread::Priority::Low )
        {
            return *( queues->at( 0 ) );
        }
        else if( priority == Thread::Priority::Normal )
        {
            return *( queues->at( 1 ) );
        }
        else if( priority == Thread::Priority::High )
        {
            return *( queues->at( 2 ) );
        }
        
        throw std::runtime_error( "Invalid Global Dispatch Queue Priority" );
    }
    
    Queue & Queue::Low()
    {
        return Global( Thread::Priority::Low );
    }
    
    Queue & Queue::Normal()
    {
        return Global( Thread::Priority::Normal );
    }
    
    Queue & Queue::High()
    {
        return Global( Thread::Priority::High );
    }
    
    Queue::Queue( const std::string & label, Kind kind, Thread::Priority priority ):
        impl( std::make_unique< IMPL >( label, kind, priority ) )
    {}
    
    Queue::~Queue()
    {}
    
    bool Queue::operator ==( const Queue & o ) const
    {
        return this->impl->_uuid == o.impl->_uuid;
    }
    
    bool Queue::operator !=( const Queue & o ) const
    {
        return !operator ==( o );
    }
    
    UUID Queue::uuid() const
    {
        return this->impl->_uuid;
    }
    
    std::string Queue::label() const
    {
        return this->impl->_label;
    }
    
    Queue::Kind Queue::kind() const
    {
        return this->impl->_kind;
    }
    
    Thread::Priority Queue::priority() const
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
        this->impl->_rl.addTimer( timer );
    }
    
    void Queue::unschedule( const Timer & timer )
    {
        this->impl->_rl.removeTimer( timer );
    }
    
    Queue::IMPL::IMPL( const std::string & label, Kind kind, Thread::Priority priority ):
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
    {
        this->_rl.stop();
    }
    
    void Queue::IMPL::_run()
    {
        Thread::SetName(     this->_label );
        Thread::SetPriority( this->_priority );
        
        this->_rl.run();
    }
}
