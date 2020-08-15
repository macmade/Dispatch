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
    
    uint64_t Interval::value() const
    {
        return this->impl->_value;
    }
    
    Interval::Kind Interval::kind() const
    {
        return this->impl->_kind;
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
