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
 * @header      Interval.hpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#ifndef DISPATCH_INTERVAL_HPP
#define DISPATCH_INTERVAL_HPP

#include <memory>
#include <algorithm>
#include <cstdint>
#include <chrono>
#include <type_traits>

namespace Dispatch
{
    class Interval
    {
        public:
            
            enum class Kind: int
            {
                Nanoseconds,
                Microseconds,
                Milliseconds,
                Seconds,
                Minutes,
                Hours,
                Days
            };
            
            static Interval FromNanoseconds(  uint64_t value );
            static Interval FromMicroseconds( uint64_t value );
            static Interval FromMilliseconds( uint64_t value );
            static Interval FromSeconds(      uint64_t value );
            static Interval FromMinutes(      uint64_t value );
            static Interval FromHours(        uint64_t value );
            static Interval FromDays(         uint64_t value );
            
            template< class T, class U >
            Interval( const std::chrono::duration< T, U > & duration, typename std::enable_if< std::is_signed< T >::value >::type * = nullptr ):
                Interval
                (
                    ( duration.count() < 0 ) ? 0 : static_cast< uint64_t >( std::chrono::duration_cast< std::chrono::nanoseconds >( duration ).count() ),
                    Kind::Nanoseconds
                )
            {}
            
            template< class T, class U >
            Interval( const std::chrono::duration< T, U > & duration, typename std::enable_if< std::is_unsigned< T >::value >::type * = nullptr ):
                Interval
                (
                    std::chrono::duration_cast< std::chrono::duration< uint64_t, std::nano > >( duration ).count(),
                    Kind::Nanoseconds
                )
            {}
            
            Interval( uint64_t value, Kind kind );
            Interval( const std::chrono::nanoseconds duration );
            Interval( const std::chrono::microseconds duration );
            Interval( const std::chrono::milliseconds duration );
            Interval( const std::chrono::seconds duration );
            Interval( const std::chrono::minutes duration );
            Interval( const std::chrono::hours duration );
            Interval( const Interval & o );
            Interval( Interval && o ) noexcept;
            ~Interval();
            
            Interval & operator =( Interval o );
            
            bool operator ==( const Interval & o );
            bool operator !=( const Interval & o );
            bool operator <(  const Interval & o );
            bool operator >(  const Interval & o );
            bool operator <=( const Interval & o );
            bool operator >=( const Interval & o );
            
            Interval & operator ++( void );
            Interval   operator ++( int );
            Interval & operator --( void );
            Interval   operator --( int );
            
            Interval & operator +=( const Interval & value );
            Interval & operator -=( const Interval & value );
            
            Interval operator +( const Interval & value );
            Interval operator -( const Interval & value );
            
            uint64_t value() const;
            Kind     kind()  const;
            
            operator std::chrono::nanoseconds()  const;
            operator std::chrono::microseconds() const;
            operator std::chrono::milliseconds() const;
            operator std::chrono::seconds()      const;
            operator std::chrono::minutes()      const;
            operator std::chrono::hours()        const;
            
            std::chrono::nanoseconds  nanoseconds()  const;
            std::chrono::microseconds microseconds() const;
            std::chrono::milliseconds milliseconds() const;
            std::chrono::seconds      seconds()      const;
            std::chrono::minutes      minutes()      const;
            std::chrono::hours        hours()        const;
            
            template< typename T, typename U >
            operator std::chrono::duration< T, U > () const
            {
                return this->duration< T, U >();
            }
            
            template< typename T, typename U >
            std::chrono::duration< T, U > duration() const
            {
                std::chrono::nanoseconds ns( this->nanoseconds() );
                
                return std::chrono::duration_cast< std::chrono::duration< T, U > >( ns );
            }
            
            friend void swap( Interval & o1, Interval & o2 );
            
        private:
            
            class IMPL;
            
            std::unique_ptr< IMPL > impl;
    };
}

#endif /* DISPATCH_INTERVAL_HPP */
