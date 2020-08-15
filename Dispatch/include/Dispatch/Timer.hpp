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
 * @header      Timer.hpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#ifndef DISPATCH_TIMER_HPP
#define DISPATCH_TIMER_HPP

#include <memory>
#include <algorithm>
#include <Dispatch/UUID.hpp>
#include <Dispatch/Interval.hpp>
#include <Dispatch/Action.hpp>

namespace Dispatch
{
    class Timer
    {
        public:
            
            enum class Kind
            {
                Repeating,
                Transient
            };
            
            Timer( const Interval & interval, const Action & action );
            Timer( const Interval & interval, Kind kind, const Action & action );
            Timer( const Timer & o );
            Timer( Timer && o ) noexcept;
            ~Timer();
            
            Timer & operator =( Timer o );
            
            bool operator ==( const Timer & o ) const;
            bool operator !=( const Timer & o ) const;
            
            UUID     uuid()     const;
            Interval interval() const;
            Kind     kind()     const;
            Action   action()   const;
            
            friend void swap( Timer & o1, Timer & o2 );
            
        private:
            
            class IMPL;
            
            std::unique_ptr< IMPL > impl;
    };
}

#endif /* DISPATCH_TIMER_HPP */
