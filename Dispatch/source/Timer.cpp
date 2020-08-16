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
    using Clock     = std::chrono::high_resolution_clock;
    using TimePoint = Clock::time_point;
    
    class Timer::IMPL
    {
        public:
            
            IMPL( const Interval & interval, Kind kind, const Interval & start, const Action & action );
            IMPL( const IMPL & o );
            ~IMPL();
            
            UUID      _uuid;
            Interval  _interval;
            Interval  _start;
            Kind      _kind;
            Action    _action;
            TimePoint _created;
            TimePoint _lastRun;
    };
    
    Timer::Timer( const Interval & interval, const Action & action ):
        Timer( interval, Kind::Repeating, action )
    {}
    
    Timer::Timer( const Interval & interval, Kind kind, const Action & action ):
        Timer( interval, kind, { 0, Interval::Kind::Nanoseconds }, action )
    {}
    
    Timer::Timer( const Interval & interval, Kind kind, const Interval & start, const Action & action ):
        impl( std::make_unique< IMPL >( interval, kind, start, action ) )
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
    
    bool Timer::shouldRun() const
    {
        if( this->impl->_lastRun < this->impl->_created )
        {
            return Clock::now() >= this->impl->_created + this->impl->_start.nanoseconds();
        }
        
        if( this->impl->_kind == Kind::Transient )
        {
            return false;
        }
        
        return Clock::now() >= this->impl->_lastRun + this->impl->_interval.nanoseconds();
    }
    
    void Timer::run()
    {
        this->impl->_action.execute();
        
        this->impl->_lastRun = Clock::now();
    }
    
    void Timer::runIfNecessary()
    {
        if( this->shouldRun() )
        {
            this->run();
        }
    }
    
    void swap( Timer & o1, Timer & o2 )
    {
        using std::swap;
        
        swap( o1.impl, o2.impl );
    }
    
    Timer::IMPL::IMPL( const Interval & interval, Kind kind, const Interval & start, const Action & action ):
        _interval( interval ),
        _start(    start ),
        _kind(     kind ),
        _action(   action ),
        _created(  Clock::now() )
    {}
    
    Timer::IMPL::IMPL( const IMPL & o ):
        _uuid(     o._uuid ),
        _interval( o._interval ),
        _start(    o._start ),
        _kind(     o._kind ),
        _action(   o._action ),
        _created(  o._created ),
        _lastRun(  o._lastRun )
    {}
    
    Timer::IMPL::~IMPL()
    {}
}
