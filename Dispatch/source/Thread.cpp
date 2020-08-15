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
 * @file        Thread.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <Dispatch/Thread.hpp>

#ifdef __APPLE__
#include <pthread.h>
#include <string.h>
#endif

namespace Dispatch
{
    void Thread::SetPriority( Priority priority )
    {
        #ifdef __APPLE__
        
        struct sched_param sp;
        
        memset( &sp, 0, sizeof( struct sched_param ) );
        
        if( priority == Priority::Low )
        {
            sp.sched_priority = sched_get_priority_min( SCHED_RR );
            
            pthread_setschedparam( pthread_self(), SCHED_RR, &sp );
        }
        else if( priority == Priority::Normal )
        {
            sp.sched_priority = sched_get_priority_min( SCHED_RR );
            
            pthread_setschedparam( pthread_self(), SCHED_RR, &sp );
        }
        
        #endif
    }
    
    void Thread::SetName( const std::string & name )
    {
        #ifdef __APPLE__
        
        pthread_setname_np( name.c_str() );
        
        #endif
    }
}
