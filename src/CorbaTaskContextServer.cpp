#include "CorbaTaskContextServer.hpp"
#include <rtt/remote/TaskContextServerFactory.hpp>
#include <rtt/remote/ITypeGenerator.hpp>


#include <rtt/plugin/Plugin.hpp>



using namespace RTT::Communication;

/**
 * @brief Constructor of the Corba Task Context Server.
 */
CorbaTaskContextServer::CorbaTaskContextServer()
{

}

/**
 * @brief Destructor of the Corba Task Context Server.
 */
CorbaTaskContextServer::~CorbaTaskContextServer()
{

}

/**
 * @brief This method sets up the task context server generator for the
 * Corba implementation, i.e. it registers this type at the generator.
 *
 * @return void
 */
void CorbaTaskContextServer::RegisterGenerators(std::string modelName)
{
    // Create a shared pointer to a typed TCS generator for the corba implementation
    TypeGenerator<RTT::Communication::ITaskContextServer,CorbaTaskContextServer>::shared_ptr pCorbaTCSGenerator(new TypeGenerator<RTT::Communication::ITaskContextServer,CorbaTaskContextServer>("CORBA_TCS")) ;
//     ITaskContextServerGenerator::shared_ptr pCorbaTCSGenerator(new TypedTaskContextServerGenerator<CorbaTaskContextServer>("CORBA_TCS"));
	
//        ITypeGenerator::shared_ptr pCorbaTCSGenerator(new TypeGenerator<RTT::Communication::ITaskContextServer,CorbaTaskContextServer>("CORBA_TCS"));
    // Register the pointer to this typed generator at the TCS factory
    TaskContextServerFactory::GetInstance()->RegisterTaskContextServerGenerator(modelName,pCorbaTCSGenerator);
//     Factory::GetInstance()->RegisterTaskContextServerGenerator(modelName, TypeGenerator<RTT::Communication::ITaskContextServer,CorbaTaskContextServer>);
};

/**
 * @brief Registers the given taskcontext at the given name services.
 *
 * @param pTaskContext Reference to the task context.
 * @return bool
 */
bool CorbaTaskContextServer::AttachTo(RTT::TaskContext *pTaskContext, int argc, char *argv[])
{
    
    RTT::corba::TaskContextServer::Create(pTaskContext);
    RTT::corba::CorbaDispatcher::Instance(pTaskContext->ports(), ORO_SCHED_OTHER, RTT::os::LowestPriority);

    return true;
};

/**
 * @brief Starts the execution of task context.
 *
 * @param StartThreaded Determines, whether the task context shall be started in the current thread or in its own thread.
 * @return bool
 */
bool CorbaTaskContextServer::Start(bool StartThreaded)
{
    RTT::corba::TaskContextServer::ThreadOrb(ORO_SCHED_OTHER, RTT::os::LowestPriority, 0);
    return true;
}

/**
 * @brief Stops the execution of the task context.
 *
 * @return bool
 */
bool CorbaTaskContextServer::Stop()
{
  RTT::corba::TaskContextServer::ShutdownOrb();
  return true;
}

/**
 * @brief Deletes a TaskContext server for a given task context.
 *
 * @param pTaskContext Reference to the task context.
 * @return bool
 */
bool CorbaTaskContextServer::Delete(RTT::TaskContext* pTaskContext)
{
  RTT::corba::TaskContextServer::CleanupServer(pTaskContext);
  return true;
}
/**
 * @brief Deletes all existing task context server objects.
 *
 * @return bool
 */
bool CorbaTaskContextServer::DeleteAll()
{
  RTT::corba::TaskContextServer::CleanupServers();
  RTT::corba::TaskContextServer::DestroyOrb();
  return true;
}
