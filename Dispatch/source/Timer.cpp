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
 * @file        Timer.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <Dispatch/Timer.hpp>

namespace Dispatch
{
    class Timer::IMPL
    {
        public:
            
            IMPL( const Interval & interval, Kind kind, const Action & action );
            IMPL( const IMPL & o );
            ~IMPL();
            
            UUID     _uuid;
            Interval _interval;
            Kind     _kind;
            Action   _action;
    };
    
    Timer::Timer( const Interval & interval, const Action & action ):
        Timer( interval, Kind::Repeating, action )
    {}
    
    Timer::Timer( const Interval & interval, Kind kind, const Action & action ):
        impl( std::make_unique< IMPL >( interval, kind, action ) )
    {}
    
    Timer::Timer( const Timer & o ):
        impl( std::make_unique< IMPL >( *( o.impl ) ) )
    {}
    
    Timer::Timer( Timer && o ) noexcept:
        impl( std::move( o.impl ) )
    {}
    
    Timer::~Timer()
    {}
    
    Timer & Timer::operator =( Timer o )
    {
        swap( *( this ), o );
        
        return *( this );
    }
    
    bool Timer::operator ==( const Timer & o ) const
    {
        return this->impl->_uuid == o.impl->_uuid;
    }
    
    bool Timer::operator !=( const Timer & o ) const
    {
        return !operator ==( o );
    }
    
    UUID Timer::uuid() const
    {
        return this->impl->_uuid;
    }
    
    Interval Timer::interval() const
    {
        return this->impl->_interval;
    }
    
    Timer::Kind Timer::kind() const
    {
        return this->impl->_kind;
    }
    
    Action Timer::action() const
    {
        return this->impl->_action;
    }
    
    void swap( Timer & o1, Timer & o2 )
    {
        using std::swap;
        
        swap( o1.impl, o2.impl );
    }
    
    Timer::IMPL::IMPL( const Interval & interval, Kind kind, const Action & action ):
        _interval( interval ),
        _kind(     kind ),
        _action(   action )
    {}
    
    Timer::IMPL::IMPL( const IMPL & o ):
        _uuid(     o._uuid ),
        _interval( o._interval ),
        _kind(     o._kind ),
        _action(   o._action )
    {}
    
    Timer::IMPL::~IMPL()
    {}
}
