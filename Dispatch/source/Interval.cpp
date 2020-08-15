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
 * @file        Interval.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <Dispatch/Interval.hpp>

namespace Dispatch
{
    class Interval::IMPL
    {
        public:
            
            IMPL( uint64_t value, Kind kind );
            IMPL( const IMPL & o );
            ~IMPL();
            
            uint64_t _value;
            Kind     _kind;
    };
    
    Interval Interval::FromNanoseconds( uint64_t value )
    {
        return { value, Kind::Nanoseconds };
    }
    
    Interval Interval::FromMicroseconds( uint64_t value )
    {
        return { value, Kind::Microseconds };
    }
    
    Interval Interval::FromMilliseconds( uint64_t value )
    {
        return { value, Kind::Milliseconds };
    }
    
    Interval Interval::FromSeconds( uint64_t value )
    {
        return { value, Kind::Seconds };
    }
    
    Interval Interval::FromMinutes( uint64_t value )
    {
        return { value, Kind::Minutes };
    }
    
    Interval Interval::FromHours( uint64_t value )
    {
        return { value, Kind::Hours };
    }
    
    Interval Interval::FromDays( uint64_t value )
    {
        return { value, Kind::Days };
    }
    
    Interval::Interval( uint64_t value, Kind kind ):
        impl( std::make_unique< IMPL >( value, kind ) )
    {}
    
    Interval::Interval( const std::chrono::nanoseconds duration ):
        Interval
        (
            ( duration.count() < 0 ) ? 0 : static_cast< uint64_t >( duration.count() ),
            Kind::Nanoseconds
        )
    {}
    
    Interval::Interval( const std::chrono::microseconds duration ):
        Interval
        (
            ( duration.count() < 0 ) ? 0 : static_cast< uint64_t >( duration.count() ),
            Kind::Microseconds
        )
    {}
    
    Interval::Interval( const std::chrono::milliseconds duration ):
        Interval
        (
            ( duration.count() < 0 ) ? 0 : static_cast< uint64_t >( duration.count() ),
            Kind::Milliseconds
        )
    {}
    
    Interval::Interval( const std::chrono::seconds duration ):
        Interval
        (
            ( duration.count() < 0 ) ? 0 : static_cast< uint64_t >( duration.count() ),
            Kind::Seconds
        )
    {}
    
    Interval::Interval( const std::chrono::minutes duration ):
        Interval
        (
            ( duration.count() < 0 ) ? 0 : static_cast< uint64_t >( duration.count() ),
            Kind::Minutes
        )
    {}
    
    Interval::Interval( const std::chrono::hours duration ):
        Interval
        (
            ( duration.count() < 0 ) ? 0 : static_cast< uint64_t >( duration.count() ),
            Kind::Hours
        )
    {}
    
    Interval::Interval( const Interval & o ):
        impl( std::make_unique< IMPL >( *( o.impl ) ) )
    {}
    
    Interval::Interval( Interval && o ) noexcept:
        impl( std::move( o.impl ) )
    {}
    
    Interval::~Interval()
    {}
    
    Interval & Interval::operator =( Interval o )
    {
        swap( *( this ), o );
        
        return *( this );
    }
    
    bool Interval::operator ==( const Interval & o )
    {
        return this->nanoseconds() == o.nanoseconds();
    }
    
    bool Interval::operator !=( const Interval & o )
    {
        return this->nanoseconds() != o.nanoseconds();
    }
    
    bool Interval::operator <( const Interval & o )
    {
        return this->nanoseconds() < o.nanoseconds();
    }
    
    bool Interval::operator >( const Interval & o )
    {
        return this->nanoseconds() > o.nanoseconds();
    }
    
    bool Interval::operator <=( const Interval & o )
    {
        return this->nanoseconds() <= o.nanoseconds();
    }
    
    bool Interval::operator >=( const Interval & o )
    {
        return this->nanoseconds() >= o.nanoseconds();
    }
    
    uint64_t Interval::value() const
    {
        return this->impl->_value;
    }
    
    Interval::Kind Interval::kind() const
    {
        return this->impl->_kind;
    }
    
    Interval::operator std::chrono::nanoseconds() const
    {
        return this->nanoseconds();
    }
    
    Interval::operator std::chrono::microseconds() const
    {
        return this->microseconds();
    }
    
    Interval::operator std::chrono::milliseconds() const
    {
        return this->milliseconds();
    }
    
    Interval::operator std::chrono::seconds() const
    {
        return this->seconds();
    }
    
    Interval::operator std::chrono::minutes() const
    {
        return this->minutes();
    }
    
    Interval::operator std::chrono::hours() const
    {
        return this->hours();
    }
    
    std::chrono::nanoseconds Interval::nanoseconds()  const
    {
        int64_t value( static_cast< int64_t >( this->impl->_value ) );
        
        switch( this->impl->_kind )
        {
            case Kind::Nanoseconds:  return std::chrono::nanoseconds( value );
            case Kind::Microseconds: return std::chrono::nanoseconds( value * 1000 );
            case Kind::Milliseconds: return std::chrono::nanoseconds( value * 1000 * 1000 );
            case Kind::Seconds:      return std::chrono::nanoseconds( value * 1000 * 1000 * 1000 );
            case Kind::Minutes:      return std::chrono::nanoseconds( value * 1000 * 1000 * 1000 * 60 );
            case Kind::Hours:        return std::chrono::nanoseconds( value * 1000 * 1000 * 1000 * 60 * 60 );
            case Kind::Days:         return std::chrono::nanoseconds( value * 1000 * 1000 * 1000 * 60 * 60 * 24 );
        }
    }
    
    std::chrono::microseconds Interval::microseconds() const
    {
        return std::chrono::duration_cast< std::chrono::microseconds >( this->nanoseconds() );
    }
    
    std::chrono::milliseconds Interval::milliseconds() const
    {
        return std::chrono::duration_cast< std::chrono::milliseconds >( this->nanoseconds() );
    }
    
    std::chrono::seconds Interval::seconds() const
    {
        return std::chrono::duration_cast< std::chrono::seconds >( this->nanoseconds() );
    }
    
    std::chrono::minutes Interval::minutes() const
    {
        return std::chrono::duration_cast< std::chrono::minutes >( this->nanoseconds() );
    }
    
    std::chrono::hours Interval::hours() const
    {
        return std::chrono::duration_cast< std::chrono::hours >( this->nanoseconds() );
    }
    
    void swap( Interval & o1, Interval & o2 )
    {
        using std::swap;
        
        swap( o1.impl, o2.impl );
    }
    
    Interval::IMPL::IMPL( uint64_t value, Kind kind ):
        _value( value ),
        _kind(  kind )
    {}
    
    Interval::IMPL::IMPL( const IMPL & o ):
        _value( o._value ),
        _kind(  o._kind )
    {}
    
    Interval::IMPL::~IMPL()
    {}
}
