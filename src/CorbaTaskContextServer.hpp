/***************************************************************************
  tag: Bernd Langpap  Wed Jan 18 14:09:48 CET 2006  INamingService.hpp

                        CorbaTaskContextServer.hpp -  description
                           -------------------
    begin                : Mon March 17 2015
    copyright            : (C) 2015 Bernd Langpap
    email                : bernd.langpap@dfki.de

 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU General Public                   *
 *   License as published by the Free Software Foundation;                 *
 *   version 2 of the License.                                             *
 *                                                                         *
 *   As a special exception, you may use this file as part of a free       *
 *   software library without restriction.  Specifically, if other files   *
 *   instantiate templates or use macros or inline functions from this     *
 *   file, or you compile this file and link it with other files to        *
 *   produce an executable, this file does not by itself cause the         *
 *   resulting executable to be covered by the GNU General Public          *
 *   License.  This exception does not however invalidate any other        *
 *   reasons why the executable file might be covered by the GNU General   *
 *   Public License.                                                       *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU General Public             *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/
#ifndef REMOTE_CORBATASKCONTEXTSERVER_HPP
#define REMOTE_CORBATASKCONTEXTSERVER_HPP

#include <string>
#include <rtt/remote/ITaskContextServer.hpp>


#include <omniORB4/CORBA.h>




#include <rtt/transports/corba/ApplicationServer.hpp>
#include <rtt/transports/corba/TaskContextServer.hpp>
#include <rtt/transports/corba/CorbaDispatcher.hpp>


#ifdef CORBA_IS_TAO
#include <tao/PortableServer/PortableServer.h>
#else
#include <omniORB4/poa.h>
#endif

namespace RTT
{
namespace Communication
{
/**
  * @brief This class realizes the Task Context Server for Corba by implementing the task context server interface.
  *
  */
class CorbaTaskContextServer : public RTT::Communication::ITaskContextServer
{
public:
    /**
    * The orb of this process.
    */
    static CORBA::ORB_var orb;

    /**
     * The root POA of this process.
     */
    static PortableServer::POA_var rootPOA;
    
    PortableServer::POA_var mpoa;

  
    // Ctor / Dtor
    CorbaTaskContextServer();
    ~CorbaTaskContextServer();
    
    
   typedef std::map<TaskContext*, CorbaTaskContextServer*> ServerMap;
   static ServerMap servers;
    

    // Register generators at factory
   static void RegisterGenerators(std::string modelName);
    
    // Implementation of the task context server interface
    virtual bool AttachTo(RTT::TaskContext *pTaskContext, int argc, char* argv[]);
    virtual bool Start(bool StartThreaded = false);
    virtual bool Stop();
    virtual bool Delete(RTT::TaskContext *pTaskContext);
    virtual bool DeleteAll();

   
};

}
}




#endif // REMOTE_CORBATASKCONTEXTSERVER_HPP
