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
 * @file        Dispatch-Timer.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <XSTest/XSTest.hpp>
#include <Dispatch.hpp>
#include <sstream>

XSTest( Timer, CTOR_Interval_Action )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t2( {  0, Dispatch::Interval::Kind::Minutes }, nullptr );
    
    XSTestAssertTrue( t1.uuid().string().size() > 0 );
    XSTestAssertTrue( t2.uuid().string().size() > 0 );
    
    XSTestAssertEqual( t1.interval().value(), 42ULL );
    XSTestAssertEqual( t2.interval().value(),  0ULL );
    
    XSTestAssertEqual( t1.interval().kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( t2.interval().kind(), Dispatch::Interval::Kind::Minutes );
    
    XSTestAssertEqual( t1.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( t2.kind(), Dispatch::Timer::Kind::Repeating );
    
    XSTestAssertNotEqual( t1.action(), nullptr );
    XSTestAssertEqual(    t2.action(), nullptr );
}

XSTest( Timer, CTOR_Interval_Kind_Action )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, []() {} );
    Dispatch::Timer t2( {  0, Dispatch::Interval::Kind::Minutes }, Dispatch::Timer::Kind::Transient, nullptr );
    
    XSTestAssertTrue( t1.uuid().string().size() > 0 );
    XSTestAssertTrue( t2.uuid().string().size() > 0 );
    
    XSTestAssertEqual( t1.interval().value(), 42ULL );
    XSTestAssertEqual( t2.interval().value(),  0ULL );
    
    XSTestAssertEqual( t1.interval().kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( t2.interval().kind(), Dispatch::Interval::Kind::Minutes );
    
    XSTestAssertEqual( t1.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( t2.kind(), Dispatch::Timer::Kind::Transient );
    
    XSTestAssertNotEqual( t1.action(), nullptr );
    XSTestAssertEqual(    t2.action(), nullptr );
}

XSTest( Timer, CTOR_Interval_Kind_Start_Action )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t2( {  0, Dispatch::Interval::Kind::Minutes }, Dispatch::Timer::Kind::Transient, { 0, Dispatch::Interval::Kind::Seconds }, nullptr );
    
    XSTestAssertTrue( t1.uuid().string().size() > 0 );
    XSTestAssertTrue( t2.uuid().string().size() > 0 );
    
    XSTestAssertEqual( t1.interval().value(), 42ULL );
    XSTestAssertEqual( t2.interval().value(),  0ULL );
    
    XSTestAssertEqual( t1.interval().kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( t2.interval().kind(), Dispatch::Interval::Kind::Minutes );
    
    XSTestAssertEqual( t1.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( t2.kind(), Dispatch::Timer::Kind::Transient );
    
    XSTestAssertNotEqual( t1.action(), nullptr );
    XSTestAssertEqual(    t2.action(), nullptr );
}

XSTest( Timer, CCTOR )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t2( {  0, Dispatch::Interval::Kind::Minutes }, Dispatch::Timer::Kind::Transient, { 0, Dispatch::Interval::Kind::Seconds }, nullptr );
    Dispatch::Timer c1( t1 );
    Dispatch::Timer c2( t2 );
    
    XSTestAssertTrue( t1.uuid().string().size() > 0 );
    XSTestAssertTrue( c1.uuid().string().size() > 0 );
    XSTestAssertTrue( t2.uuid().string().size() > 0 );
    XSTestAssertTrue( c2.uuid().string().size() > 0 );
    
    XSTestAssertEqual( t1.interval().value(), 42ULL );
    XSTestAssertEqual( c1.interval().value(), 42ULL );
    XSTestAssertEqual( t2.interval().value(),  0ULL );
    XSTestAssertEqual( c2.interval().value(),  0ULL );
    
    XSTestAssertEqual( t1.interval().kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( c1.interval().kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( t2.interval().kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( c2.interval().kind(), Dispatch::Interval::Kind::Minutes );
    
    XSTestAssertEqual( t1.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( c1.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( t2.kind(), Dispatch::Timer::Kind::Transient );
    XSTestAssertEqual( c2.kind(), Dispatch::Timer::Kind::Transient );
    
    XSTestAssertNotEqual( t1.action(), nullptr );
    XSTestAssertNotEqual( c1.action(), nullptr );
    XSTestAssertEqual(    t2.action(), nullptr );
    XSTestAssertEqual(    c2.action(), nullptr );
}

XSTest( Timer, MCTOR )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t2( {  0, Dispatch::Interval::Kind::Minutes }, Dispatch::Timer::Kind::Transient, { 0, Dispatch::Interval::Kind::Seconds }, nullptr );
    Dispatch::Timer c1( std::move( t1 ) );
    Dispatch::Timer c2( std::move( t2 ) );
    
    XSTestAssertTrue( c1.uuid().string().size() > 0 );
    XSTestAssertTrue( c2.uuid().string().size() > 0 );
    
    XSTestAssertEqual( c1.interval().value(), 42ULL );
    XSTestAssertEqual( c2.interval().value(),  0ULL );
    
    XSTestAssertEqual( c1.interval().kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( c2.interval().kind(), Dispatch::Interval::Kind::Minutes );
    
    XSTestAssertEqual( c1.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( c2.kind(), Dispatch::Timer::Kind::Transient );
    
    XSTestAssertNotEqual( c1.action(), nullptr );
    XSTestAssertEqual(    c2.action(), nullptr );
}

XSTest( Timer, OperatorAssign )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t2( {  0, Dispatch::Interval::Kind::Minutes }, Dispatch::Timer::Kind::Transient, { 0, Dispatch::Interval::Kind::Seconds }, nullptr );
    Dispatch::Timer t3( {  1, Dispatch::Interval::Kind::Hours },   Dispatch::Timer::Kind::Transient, { 0, Dispatch::Interval::Kind::Seconds }, nullptr );
    Dispatch::Timer t4( {  1, Dispatch::Interval::Kind::Hours },   Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    
    t3 = t1;
    t4 = t2;
    
    XSTestAssertTrue( t1.uuid().string().size() > 0 );
    XSTestAssertTrue( t3.uuid().string().size() > 0 );
    XSTestAssertTrue( t2.uuid().string().size() > 0 );
    XSTestAssertTrue( t4.uuid().string().size() > 0 );
    
    XSTestAssertEqual( t1.interval().value(), 42ULL );
    XSTestAssertEqual( t3.interval().value(), 42ULL );
    XSTestAssertEqual( t2.interval().value(),  0ULL );
    XSTestAssertEqual( t4.interval().value(),  0ULL );
    
    XSTestAssertEqual( t1.interval().kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( t3.interval().kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( t2.interval().kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( t4.interval().kind(), Dispatch::Interval::Kind::Minutes );
    
    XSTestAssertEqual( t1.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( t3.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( t2.kind(), Dispatch::Timer::Kind::Transient );
    XSTestAssertEqual( t4.kind(), Dispatch::Timer::Kind::Transient );
    
    XSTestAssertNotEqual( t1.action(), nullptr );
    XSTestAssertNotEqual( t3.action(), nullptr );
    XSTestAssertEqual(    t2.action(), nullptr );
    XSTestAssertEqual(    t4.action(), nullptr );
}

XSTest( Timer, OperatorEqual )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t2( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t3( t1 );
    
    XSTestAssertFalse( t1 == t2 );
    XSTestAssertTrue(  t1 == t3 );
}

XSTest( Timer, OperatorNotEqual )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t2( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t3( t1 );
    
    XSTestAssertTrue(  t1 != t2 );
    XSTestAssertFalse( t1 != t3 );
}

XSTest( Timer, UUID )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t2( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t3( t1 );
    
    XSTestAssertTrue( t1.uuid().string().size() > 0 );
    XSTestAssertTrue( t2.uuid().string().size() > 0 );
    XSTestAssertTrue( t3.uuid().string().size() > 0 );
    
    XSTestAssertFalse( t1.uuid() == t2.uuid() );
    XSTestAssertTrue(  t1.uuid() == t3.uuid() );
}

XSTest( Timer, Interval )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Milliseconds }, []() {} );
    Dispatch::Timer t2( {  1, Dispatch::Interval::Kind::Seconds },      []() {} );
    
    XSTestAssertEqual( t1.interval().value(), 42ULL );
    XSTestAssertEqual( t2.interval().value(),  1ULL );
    
    XSTestAssertEqual( t1.interval().kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( t2.interval().kind(), Dispatch::Interval::Kind::Seconds );
}

XSTest( Timer, Kind )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Milliseconds }, Dispatch::Timer::Kind::Repeating, []() {} );
    Dispatch::Timer t2( {  1, Dispatch::Interval::Kind::Seconds },      Dispatch::Timer::Kind::Transient, []() {} );
    
    XSTestAssertEqual( t1.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( t2.kind(), Dispatch::Timer::Kind::Transient );
}

XSTest( Timer, Action )
{
    int             x( 0 );
    int             y( 0 );
    Dispatch::Timer t1( { 1, Dispatch::Interval::Kind::Seconds }, [ & ]() { x++; } );
    Dispatch::Timer t2( { 1, Dispatch::Interval::Kind::Seconds }, [ & ]() { y++; } );
    Dispatch::Timer t3( { 1, Dispatch::Interval::Kind::Seconds }, nullptr );
    
    XSTestAssertNotEqual( t1.action(), nullptr );
    XSTestAssertNotEqual( t2.action(), nullptr );
    XSTestAssertEqual(    t3.action(), nullptr );
    
    XSTestAssertEqual( x, 0 );
    XSTestAssertEqual( y, 0 );
    
    t1.action().execute();
    
    XSTestAssertEqual( x, 1 );
    XSTestAssertEqual( y, 0 );
    
    t2.action().execute();
    
    XSTestAssertEqual( x, 1 );
    XSTestAssertEqual( y, 1 );
}

XSTest( Timer, ShouldRun )
{
    
}

XSTest( Timer, Run )
{
    
}

XSTest( Timer, RunIfNecessary )
{
    
}

XSTest( Timer, Swap )
{
    Dispatch::Timer t1( { 42, Dispatch::Interval::Kind::Seconds }, Dispatch::Timer::Kind::Repeating, { 0, Dispatch::Interval::Kind::Seconds }, []() {} );
    Dispatch::Timer t2( {  0, Dispatch::Interval::Kind::Minutes }, Dispatch::Timer::Kind::Transient, { 0, Dispatch::Interval::Kind::Seconds }, nullptr );
    Dispatch::Timer c1( t1 );
    Dispatch::Timer c2( t2 );
    
    XSTestAssertTrue( t1.uuid().string().size() > 0 );
    XSTestAssertTrue( t2.uuid().string().size() > 0 );
    
    XSTestAssertEqual( t1.interval().value(), 42ULL );
    XSTestAssertEqual( t2.interval().value(),  0ULL );
    
    XSTestAssertEqual( t1.interval().kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( t2.interval().kind(), Dispatch::Interval::Kind::Minutes );
    
    XSTestAssertEqual( t1.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( t2.kind(), Dispatch::Timer::Kind::Transient );
    
    XSTestAssertNotEqual( t1.action(), nullptr );
    XSTestAssertEqual(    t2.action(), nullptr );
    
    XSTestAssertTrue(  t1 == c1 );
    XSTestAssertFalse( t1 == c2 );
    XSTestAssertTrue(  t2 == c2 );
    XSTestAssertFalse( t2 == c1 );
    
    swap( t1, t2 );
    
    XSTestAssertTrue( t2.uuid().string().size() > 0 );
    XSTestAssertTrue( t1.uuid().string().size() > 0 );
    
    XSTestAssertEqual( t2.interval().value(), 42ULL );
    XSTestAssertEqual( t1.interval().value(),  0ULL );
    
    XSTestAssertEqual( t2.interval().kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( t1.interval().kind(), Dispatch::Interval::Kind::Minutes );
    
    XSTestAssertEqual( t2.kind(), Dispatch::Timer::Kind::Repeating );
    XSTestAssertEqual( t1.kind(), Dispatch::Timer::Kind::Transient );
    
    XSTestAssertNotEqual( t2.action(), nullptr );
    XSTestAssertEqual(    t1.action(), nullptr );
    
    XSTestAssertTrue(  t2 == c1 );
    XSTestAssertFalse( t2 == c2 );
    XSTestAssertTrue(  t1 == c2 );
    XSTestAssertFalse( t1 == c1 );
}