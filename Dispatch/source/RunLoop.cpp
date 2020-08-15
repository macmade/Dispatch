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
 * @file        RunLoop.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <Dispatch/RunLoop.hpp>
#include <atomic>
#include <mutex>
#include <thread>
#include <condition_variable>

namespace Dispatch
{
    class RunLoop::IMPL
    {
        public:
            
            IMPL();
            ~IMPL();
            
            bool                        _running;
            bool                        _stopping;
            std::recursive_mutex        _rmtx;
            std::condition_variable_any _cv;
    };
    
    RunLoop::RunLoop():
        impl( std::make_unique< IMPL >() )
    {}
    
    RunLoop::~RunLoop()
    {}
    
    RunLoop::RunStatus RunLoop::run()
    {
        bool current( false );
        
        while( true )
        {
            {
                std::lock_guard< std::recursive_mutex > l( this->impl->_rmtx );
                
                if( this->impl->_stopping && current )
                {
                    this->impl->_running  = false;
                    this->impl->_stopping = false;
                    
                    this->impl->_cv.notify_all();
                    
                    return RunStatus::DoneRunning;
                }
                
                if( this->impl->_running == false )
                {
                    current               = true;
                    this->impl->_running  = true;
                    this->impl->_stopping = false;
                    
                    this->impl->_cv.notify_all();
                }
                
                if( this->impl->_running && current == false )
                {
                    return RunStatus::AlreadyRunning;
                }
            }
            
            std::this_thread::yield();
        }
    }
    
    void RunLoop::stop()
    {
        std::lock_guard< std::recursive_mutex > l( this->impl->_rmtx );
        
        if( this->impl->_running == false )
        {
            return;
        }
        
        this->impl->_stopping = true;
        
        this->impl->_cv.notify_all();
    }
    
    void RunLoop::waitUntilStopped()
    {
        std::unique_lock< std::recursive_mutex > l( this->impl->_rmtx );
        
        this->impl->_cv.wait
        (
            l,
            [ & ]() -> bool
            {
                return this->impl->_running == false;
            }
        );
    }
    
    RunLoop::IMPL::IMPL():
        _running(  false ),
        _stopping( false )
    {}
    
    RunLoop::IMPL::~IMPL()
    {}
}
