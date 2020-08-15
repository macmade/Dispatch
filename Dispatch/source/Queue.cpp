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

namespace Dispatch
{
    class Queue::IMPL
    {
        public:
            
            IMPL( const std::string & label, Kind kind, Priority priority );
            IMPL( const IMPL & o );
            ~IMPL();
            
            std::string _label;
            Kind        _kind;
            Priority    _priority;
    };
    
    Queue::Queue( const std::string & label, Kind kind, Priority priority ):
        impl( std::make_unique< IMPL >( label, kind, priority ) )
    {}
    
    Queue::Queue( const Queue & o ):
        impl( std::make_unique< IMPL >( *( o.impl ) ) )
    {}
    
    Queue::Queue( Queue && o ) noexcept:
        impl( std::move( o.impl ) )
    {}
    
    Queue::~Queue()
    {}
    
    Queue & Queue::operator =( Queue o )
    {
        swap( *( this ), o );
        
        return *( this );
    }
    
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
    
    void swap( Queue & o1, Queue & o2 )
    {
        using std::swap;
        
        swap( o1.impl, o2.impl );
    }
    
    Queue::IMPL::IMPL( const std::string & label, Kind kind, Priority priority ):
        _label(    label ),
        _kind(     kind ),
        _priority( priority )
    {}
    
    Queue::IMPL::IMPL( const IMPL & o ):
        _label(    o._label ),
        _kind(     o._kind ),
        _priority( o._priority )
    {}
    
    Queue::IMPL::~IMPL()
    {}
}
