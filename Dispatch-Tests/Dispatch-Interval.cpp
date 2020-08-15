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
 * @file        Dispatch-Interval.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <XSTest/XSTest.hpp>
#include <Dispatch.hpp>

XSTest( Interval, FromNanoseconds )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromNanoseconds(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromNanoseconds( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Nanoseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Nanoseconds );
}

XSTest( Interval, FromMicroseconds )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromMicroseconds(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromMicroseconds( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Microseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Microseconds );
}

XSTest( Interval, FromMilliseconds )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromMilliseconds(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromMilliseconds( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Milliseconds );
}

XSTest( Interval, FromSeconds )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromSeconds(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromSeconds( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
}

XSTest( Interval, FromMinutes )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromMinutes(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromMinutes( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Minutes );
}

XSTest( Interval, FromHours )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromHours(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromHours( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Hours );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Hours );
}

XSTest( Interval, FromDays )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromDays(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromDays( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Days );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Days );
}

XSTest( Interval, CTOR_Duration )
{}

XSTest( Interval, CTOR )
{
    Dispatch::Interval i1( 1, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i2( 2, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i3( 3, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i4( 4, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i5( 5, Dispatch::Interval::Kind::Days );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( i4.kind(), Dispatch::Interval::Kind::Hours );
    XSTestAssertEqual( i5.kind(), Dispatch::Interval::Kind::Days );
    
    XSTestAssertEqual( i1.value(), 1ULL );
    XSTestAssertEqual( i2.value(), 2ULL );
    XSTestAssertEqual( i3.value(), 3ULL );
    XSTestAssertEqual( i4.value(), 4ULL );
    XSTestAssertEqual( i5.value(), 5ULL );
}

XSTest( Interval, CTOR_Chrono_Nanoseconds )
{
    Dispatch::Interval i1( std::chrono::nanoseconds( -1 ) );
    Dispatch::Interval i2( std::chrono::nanoseconds(  0 ) );
    Dispatch::Interval i3( std::chrono::nanoseconds( 42 ) );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(),  0ULL );
    XSTestAssertEqual( i3.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Nanoseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Nanoseconds );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Nanoseconds );
}

XSTest( Interval, CTOR_Chrono_Microseconds )
{
    Dispatch::Interval i1( std::chrono::microseconds( -1 ) );
    Dispatch::Interval i2( std::chrono::microseconds(  0 ) );
    Dispatch::Interval i3( std::chrono::microseconds( 42 ) );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(),  0ULL );
    XSTestAssertEqual( i3.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Microseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Microseconds );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Microseconds );
}

XSTest( Interval, CTOR_Chrono_Milliseconds )
{
    Dispatch::Interval i1( std::chrono::milliseconds( -1 ) );
    Dispatch::Interval i2( std::chrono::milliseconds(  0 ) );
    Dispatch::Interval i3( std::chrono::milliseconds( 42 ) );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(),  0ULL );
    XSTestAssertEqual( i3.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Milliseconds );
}

XSTest( Interval, CTOR_Chrono_Seconds )
{
    Dispatch::Interval i1( std::chrono::seconds( -1 ) );
    Dispatch::Interval i2( std::chrono::seconds(  0 ) );
    Dispatch::Interval i3( std::chrono::seconds( 42 ) );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(),  0ULL );
    XSTestAssertEqual( i3.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Seconds );
}

XSTest( Interval, CTOR_Chrono_Minutes )
{
    Dispatch::Interval i1( std::chrono::minutes( -1 ) );
    Dispatch::Interval i2( std::chrono::minutes(  0 ) );
    Dispatch::Interval i3( std::chrono::minutes( 42 ) );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(),  0ULL );
    XSTestAssertEqual( i3.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Minutes );
}

XSTest( Interval, CTOR_Chrono_Hours )
{
    Dispatch::Interval i1( std::chrono::hours( -1 ) );
    Dispatch::Interval i2( std::chrono::hours(  0 ) );
    Dispatch::Interval i3( std::chrono::hours( 42 ) );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(),  0ULL );
    XSTestAssertEqual( i3.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Hours );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Hours );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Hours );
}

XSTest( Interval, CCTOR )
{
    Dispatch::Interval i1( 1, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i2( 2, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval c1( i1 );
    Dispatch::Interval c2( i2 );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( c1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( c2.kind(), Dispatch::Interval::Kind::Seconds );
    
    XSTestAssertEqual( i1.value(), 1ULL );
    XSTestAssertEqual( c1.value(), 1ULL );
    XSTestAssertEqual( i2.value(), 2ULL );
    XSTestAssertEqual( c2.value(), 2ULL );
}

XSTest( Interval, MCTOR )
{
    Dispatch::Interval i1( 1, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i2( 2, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval m1( std::move( i1 ) );
    Dispatch::Interval m2( std::move( i2 ) );
    
    XSTestAssertEqual( m1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( m2.kind(), Dispatch::Interval::Kind::Seconds );
    
    XSTestAssertEqual( m1.value(), 1ULL );
    XSTestAssertEqual( m2.value(), 2ULL );
}

XSTest( Interval, OperatorAssign )
{
    Dispatch::Interval i1( 1, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i2( 2, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i3( 3, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i4( 4, Dispatch::Interval::Kind::Hours );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( i4.kind(), Dispatch::Interval::Kind::Hours );
    
    XSTestAssertEqual( i1.value(), 1ULL );
    XSTestAssertEqual( i2.value(), 2ULL );
    XSTestAssertEqual( i3.value(), 3ULL );
    XSTestAssertEqual( i4.value(), 4ULL );
    
    i3 = i1;
    i4 = i2;
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i4.kind(), Dispatch::Interval::Kind::Seconds );
    
    XSTestAssertEqual( i1.value(), 1ULL );
    XSTestAssertEqual( i2.value(), 2ULL );
    XSTestAssertEqual( i3.value(), 1ULL );
    XSTestAssertEqual( i4.value(), 2ULL );
}

XSTest( Interval, Value )
{
    Dispatch::Interval i1(  0, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Seconds );

    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
}

XSTest( Interval, Kind )
{
    Dispatch::Interval i1(  0, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Minutes );

    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Minutes );
}

XSTest( Interval, Nanoseconds )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( i1.nanoseconds(), 42ULL );
    XSTestAssertEqual( i2.nanoseconds(), 42000ULL );
    XSTestAssertEqual( i3.nanoseconds(), 42000000ULL );
    XSTestAssertEqual( i4.nanoseconds(), 42000000000ULL );
    XSTestAssertEqual( i5.nanoseconds(), 2520000000000ULL );
    XSTestAssertEqual( i6.nanoseconds(), 151200000000000ULL );
    XSTestAssertEqual( i7.nanoseconds(), 3628800000000000ULL );
}

XSTest( Interval, Swap )
{
    Dispatch::Interval i1(  0, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Minutes );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Minutes );
    
    swap( i1, i2 );
    
    XSTestAssertEqual( i1.value(), 42ULL );
    XSTestAssertEqual( i2.value(),  0ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
}
