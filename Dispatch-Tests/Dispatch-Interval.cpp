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

XSTest( Interval, CTOR_Duration_Signed )
{
    std::chrono::duration< int16_t, std::milli > d1( -1 );
    std::chrono::duration< int16_t, std::milli > d2( 0 );
    std::chrono::duration< int16_t, std::milli > d3( 42 );
    Dispatch::Interval                           i1( d1 );
    Dispatch::Interval                           i2( d2 );
    Dispatch::Interval                           i3( d3 );
    
    XSTestAssertEqual( i1.nanoseconds().count(), 0 );
    XSTestAssertEqual( i2.nanoseconds().count(), 0 );
    XSTestAssertEqual( i3.nanoseconds().count(), 42000000 );
}

XSTest( Interval, CTOR_Duration_Unsigned )
{
    std::chrono::duration< uint16_t, std::milli > d1( 0 );
    std::chrono::duration< uint16_t, std::milli > d2( 42 );
    Dispatch::Interval                            i1( d1 );
    Dispatch::Interval                            i2( d2 );
    
    XSTestAssertEqual( i1.nanoseconds().count(), 0 );
    XSTestAssertEqual( i2.nanoseconds().count(), 42000000 );
}

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

XSTest( Interval, OperatorEqual )
{
    Dispatch::Interval i1( 42000, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42001, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i3( 42,    Dispatch::Interval::Kind::Microseconds );
    
    XSTestAssertTrue(  i1 == i1 );
    XSTestAssertTrue(  i1 == i3 );
    XSTestAssertFalse( i1 == i2 );
    XSTestAssertFalse( i2 == i3 );
}

XSTest( Interval, OperatorNotEqual )
{
    Dispatch::Interval i1( 42000, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42001, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i3( 42,    Dispatch::Interval::Kind::Microseconds );
    
    XSTestAssertFalse( i1 != i1 );
    XSTestAssertFalse( i1 != i3 );
    XSTestAssertTrue(  i1 != i2 );
    XSTestAssertTrue(  i2 != i3 );
}

XSTest( Interval, OperatorLesser )
{}

XSTest( Interval, OperatorGreater )
{}

XSTest( Interval, OperatorLesserOrEqual )
{}

XSTest( Interval, OperatorGreaterOrEqual )
{}

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

XSTest( Interval, Operator_Chrono_Nanoseconds )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( static_cast< std::chrono::nanoseconds >( i1 ).count(), 42 );
    XSTestAssertEqual( static_cast< std::chrono::nanoseconds >( i2 ).count(), 42000 );
    XSTestAssertEqual( static_cast< std::chrono::nanoseconds >( i3 ).count(), 42000000 );
    XSTestAssertEqual( static_cast< std::chrono::nanoseconds >( i4 ).count(), 42000000000 );
    XSTestAssertEqual( static_cast< std::chrono::nanoseconds >( i5 ).count(), 2520000000000 );
    XSTestAssertEqual( static_cast< std::chrono::nanoseconds >( i6 ).count(), 151200000000000 );
    XSTestAssertEqual( static_cast< std::chrono::nanoseconds >( i7 ).count(), 3628800000000000 );
}

XSTest( Interval, Operator_Chrono_Microseconds )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( static_cast< std::chrono::microseconds >( i1 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::microseconds >( i2 ).count(), 42 );
    XSTestAssertEqual( static_cast< std::chrono::microseconds >( i3 ).count(), 42000 );
    XSTestAssertEqual( static_cast< std::chrono::microseconds >( i4 ).count(), 42000000 );
    XSTestAssertEqual( static_cast< std::chrono::microseconds >( i5 ).count(), 2520000000 );
    XSTestAssertEqual( static_cast< std::chrono::microseconds >( i6 ).count(), 151200000000 );
    XSTestAssertEqual( static_cast< std::chrono::microseconds >( i7 ).count(), 3628800000000 );
}

XSTest( Interval, Operator_Chrono_Milliseconds )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( static_cast< std::chrono::milliseconds >( i1 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::milliseconds >( i2 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::milliseconds >( i3 ).count(), 42 );
    XSTestAssertEqual( static_cast< std::chrono::milliseconds >( i4 ).count(), 42000 );
    XSTestAssertEqual( static_cast< std::chrono::milliseconds >( i5 ).count(), 2520000 );
    XSTestAssertEqual( static_cast< std::chrono::milliseconds >( i6 ).count(), 151200000 );
    XSTestAssertEqual( static_cast< std::chrono::milliseconds >( i7 ).count(), 3628800000 );
}

XSTest( Interval, Operator_Chrono_Seconds )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( static_cast< std::chrono::seconds >( i1 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::seconds >( i2 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::seconds >( i3 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::seconds >( i4 ).count(), 42 );
    XSTestAssertEqual( static_cast< std::chrono::seconds >( i5 ).count(), 2520 );
    XSTestAssertEqual( static_cast< std::chrono::seconds >( i6 ).count(), 151200 );
    XSTestAssertEqual( static_cast< std::chrono::seconds >( i7 ).count(), 3628800 );
}

XSTest( Interval, Operator_Chrono_Minutes )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( static_cast< std::chrono::minutes >( i1 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::minutes >( i2 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::minutes >( i3 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::minutes >( i4 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::minutes >( i5 ).count(), 42 );
    XSTestAssertEqual( static_cast< std::chrono::minutes >( i6 ).count(), 2520 );
    XSTestAssertEqual( static_cast< std::chrono::minutes >( i7 ).count(), 60480 );
}

XSTest( Interval, Operator_Chrono_Hours )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( static_cast< std::chrono::hours >( i1 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::hours >( i2 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::hours >( i3 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::hours >( i4 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::hours >( i5 ).count(), 0 );
    XSTestAssertEqual( static_cast< std::chrono::hours >( i6 ).count(), 42 );
    XSTestAssertEqual( static_cast< std::chrono::hours >( i7 ).count(), 1008 );
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

    XSTestAssertEqual( i1.nanoseconds().count(), 42 );
    XSTestAssertEqual( i2.nanoseconds().count(), 42000 );
    XSTestAssertEqual( i3.nanoseconds().count(), 42000000 );
    XSTestAssertEqual( i4.nanoseconds().count(), 42000000000 );
    XSTestAssertEqual( i5.nanoseconds().count(), 2520000000000 );
    XSTestAssertEqual( i6.nanoseconds().count(), 151200000000000 );
    XSTestAssertEqual( i7.nanoseconds().count(), 3628800000000000 );
}

XSTest( Interval, Microseconds )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( i1.microseconds().count(), 0 );
    XSTestAssertEqual( i2.microseconds().count(), 42 );
    XSTestAssertEqual( i3.microseconds().count(), 42000 );
    XSTestAssertEqual( i4.microseconds().count(), 42000000 );
    XSTestAssertEqual( i5.microseconds().count(), 2520000000 );
    XSTestAssertEqual( i6.microseconds().count(), 151200000000 );
    XSTestAssertEqual( i7.microseconds().count(), 3628800000000 );
}

XSTest( Interval, Milliseconds )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( i1.milliseconds().count(), 0 );
    XSTestAssertEqual( i2.milliseconds().count(), 0 );
    XSTestAssertEqual( i3.milliseconds().count(), 42 );
    XSTestAssertEqual( i4.milliseconds().count(), 42000 );
    XSTestAssertEqual( i5.milliseconds().count(), 2520000 );
    XSTestAssertEqual( i6.milliseconds().count(), 151200000 );
    XSTestAssertEqual( i7.milliseconds().count(), 3628800000 );
}

XSTest( Interval, Seconds )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( i1.seconds().count(), 0 );
    XSTestAssertEqual( i2.seconds().count(), 0 );
    XSTestAssertEqual( i3.seconds().count(), 0 );
    XSTestAssertEqual( i4.seconds().count(), 42 );
    XSTestAssertEqual( i5.seconds().count(), 2520 );
    XSTestAssertEqual( i6.seconds().count(), 151200 );
    XSTestAssertEqual( i7.seconds().count(), 3628800 );
}

XSTest( Interval, Minutes )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( i1.minutes().count(), 0 );
    XSTestAssertEqual( i2.minutes().count(), 0 );
    XSTestAssertEqual( i3.minutes().count(), 0 );
    XSTestAssertEqual( i4.minutes().count(), 0 );
    XSTestAssertEqual( i5.minutes().count(), 42 );
    XSTestAssertEqual( i6.minutes().count(), 2520 );
    XSTestAssertEqual( i7.minutes().count(), 60480 );
}

XSTest( Interval, Hours )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Microseconds );
    Dispatch::Interval i3( 42, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i4( 42, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i5( 42, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i6( 42, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i7( 42, Dispatch::Interval::Kind::Days );

    XSTestAssertEqual( i1.hours().count(), 0 );
    XSTestAssertEqual( i2.hours().count(), 0 );
    XSTestAssertEqual( i3.hours().count(), 0 );
    XSTestAssertEqual( i4.hours().count(), 0 );
    XSTestAssertEqual( i5.hours().count(), 0 );
    XSTestAssertEqual( i6.hours().count(), 42 );
    XSTestAssertEqual( i7.hours().count(), 1008 );
}

XSTest( Interval, OoeratorDuration )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Days );
    
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::nano > >( i1 ).count() ), 42 );
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::nano > >( i2 ).count() ), 3628800000000000 );
    
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::micro > >( i1 ).count() ), 0 );
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::micro > >( i2 ).count() ), 3628800000000 );
    
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::milli > >( i1 ).count() ), 0 );
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::milli > >( i2 ).count() ), 3628800000 );
    
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::ratio< 1 > > >( i1 ).count() ), 0 );
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::ratio< 1 > > >( i2 ).count() ), 3628800 );
    
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::ratio< 60 > > >( i1 ).count() ), 0 );
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::ratio< 60 > > >( i2 ).count() ), 60480 );
    
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::ratio< 3600 > > >( i1 ).count() ), 0 );
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::ratio< 3600 > > >( i2 ).count() ), 1008 );
    
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::ratio< 86400 > > >( i1 ).count() ), 0 );
    XSTestAssertEqual( ( static_cast< std::chrono::duration< int64_t, std::ratio< 86400 > > >( i2 ).count() ), 42 );
}

XSTest( Interval, Duration )
{
    Dispatch::Interval i1( 42, Dispatch::Interval::Kind::Nanoseconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Days );
    
    XSTestAssertEqual( ( i1.duration< int64_t, std::nano >().count() ), 42 );
    XSTestAssertEqual( ( i2.duration< int64_t, std::nano >().count() ), 3628800000000000 );
    
    XSTestAssertEqual( ( i1.duration< int64_t, std::micro >().count() ), 0 );
    XSTestAssertEqual( ( i2.duration< int64_t, std::micro >().count() ), 3628800000000 );
    
    XSTestAssertEqual( ( i1.duration< int64_t, std::milli >().count() ), 0 );
    XSTestAssertEqual( ( i2.duration< int64_t, std::milli >().count() ), 3628800000 );
    
    XSTestAssertEqual( ( i1.duration< int64_t, std::ratio< 1 > >().count() ), 0 );
    XSTestAssertEqual( ( i2.duration< int64_t, std::ratio< 1 > >().count() ), 3628800 );
    
    XSTestAssertEqual( ( i1.duration< int64_t, std::ratio< 60 > >().count() ), 0 );
    XSTestAssertEqual( ( i2.duration< int64_t, std::ratio< 60 > >().count() ), 60480 );
    
    XSTestAssertEqual( ( i1.duration< int64_t, std::ratio< 3600 > >().count() ), 0 );
    XSTestAssertEqual( ( i2.duration< int64_t, std::ratio< 3600 > >().count() ), 1008 );
    
    XSTestAssertEqual( ( i1.duration< int64_t, std::ratio< 86400 > >().count() ), 0 );
    XSTestAssertEqual( ( i2.duration< int64_t, std::ratio< 86400 > >().count() ), 42 );
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
