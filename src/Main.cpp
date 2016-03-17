#include <iostream>
#include <boost/program_options.hpp>

#include <rtt/remote/ITaskContextServer.hpp>
#include <rtt_corba_remote/CorbaTaskContextServer.hpp>
#include <rtt_corba_remote/CorbaNameService.hpp>
//
#include <rtt/plugin/Plugin.hpp>

//RTT::Communication::TaskContextServerCollection taskContextServers;

int main(int argc, char **argv)
{
    return 0;
}

extern "C" {
    bool loadRTTPlugin(RTT::TaskContext *t)
    {
        return loadRTTPlugin(t);
    }

    std::string getRTTPluginName()
    {
        return "rtt_remote";
    }

    std::string getRTTTargetName()
    {
        return getRTTTargetName();
    }

    
    
    
    void SetupGenerator()
    {
       // Register name service generator type at the factory
        RTT::Communication::CorbaNameService::RegisterGenerators("CorbaNameService");
       
	// Register task context server type at the factory
	RTT::Communication::CorbaTaskContextServer::RegisterGenerators("CorbaTaskContextServer");
    }

    
       RTT::Communication::INameService::shared_ptr CreateNameService()
    {
	        RTT::Communication::INameService::shared_ptr nameService =
            RTT::Communication::NameServiceFactory::GetInstance()->CreateNameService("CorbaNameService");
	    
	    return nameService;
    }
    
//     RTT::Communication::ITaskContextServer::shared_ptr CreateTaskContextServer(RTT::TaskContext *pTaskContext, int argc, char *argv[])
//     {
//         RTT::Communication::ITaskContextServer::shared_ptr tcs
//             = RTT::Communication::TaskContextServerFactory::GetInstance()->CreateTaskContextServer("CorbaTaskContextServer", pTaskContext,  argc, argv);
// 
// 
// 	
//         return tcs;
//     }
}
