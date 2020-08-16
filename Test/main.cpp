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
 * @file        main.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <Dispatch.hpp>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

int main()
{
    Dispatch::Queue::Normal().schedule
    (
        {
            Dispatch::Interval::FromSeconds( 1 ),
            []()
            {
                std::cout << "hello, world" << std::endl;
            }
        }
    );
    
    Dispatch::Queue::Normal().schedule
    (
        {
            Dispatch::Interval::FromSeconds( 1 ),
            Dispatch::Timer::Kind::Transient,
            []()
            {
                std::cout << "hello, transient" << std::endl;
            }
        }
    );
    
    Dispatch::Queue::Normal().schedule
    (
        {
            Dispatch::Interval::FromSeconds( 2 ),
            []()
            {
                std::cout << "hello, universe" << std::endl;
            }
        }
    );
    
    {
        std::mutex              mtx;
        std::unique_lock        l( mtx );
        std::condition_variable cv;
        
        cv.wait( l, []() { return false; } );
    }
    
    return 0;
}
