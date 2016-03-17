#include "CorbaNameService.hpp"
#include <rtt/remote/NameServiceFactory.hpp>
#include <rtt/remote/TaskContextServerFactory.hpp>
#include "CorbaTaskContextServer.hpp"

#include <rtt/plugin/Plugin.hpp>


using namespace RTT::Communication;

/**
 * @brief Constructor of the Corba Name Service.
 */
CorbaNameService::CorbaNameService()
{
    RTT::corba::ApplicationServer::InitOrb(0,0);
}

/**
 * @brief Destructor of the Corba Name Service.
 */
CorbaNameService::~CorbaNameService()
{

}

/**
 * @brief This method sets up the name service generator for the  * Corba implementation, 
 * i.e. it registers this type at the generator.
 * 
 * @return void
 */
void CorbaNameService::RegisterGenerators(std::string modelName)
{
  // Create a shared pointer to a typed name service generator for the corba implementation
  TypeGenerator<INameService,CorbaNameService>::shared_ptr pCorbaNameServiceGenerator(new TypeGenerator<INameService,CorbaNameService>(modelName));
//   INameServiceGenerator::shared_ptr pCorbaNameServiceGenerator( new TypedNameServiceGenerator<CorbaNameService>(modelName) );
  
  // Register the pointer to this typed generator at the name service factory
  NameServiceFactory::GetInstance()->RegisterNameServiceGenerator(modelName, pCorbaNameServiceGenerator);
}

/**
 * @brief Gets the URI for the current task context.
 * 
 * @return std::string
 */
std::string CorbaNameService::getURI(std::string Name)
{
  std::string URI = "";
  
  return URI;
}

/**
 * @brief Registers the taskcontext at the nameservice
 * 
 * @param taskcontext The task context
 * @return bool
 */
bool CorbaNameService::RegisterTaskContextServer(std::string Name, TaskContextServerCollection& tcsCollection)
{
  
  //for über alle Taskcontext und dann registrieren mit code von TaskContextServer()
 // ITypeGenerator<ITaskContextServer>::shared_ptr pTCSGenerator( new ITypeGenerator<ITaskContextServer,CorbaTaskContextServer>(Name) );
//   ITaskContextServer::shared_ptr pt();
//   
//   tcsCollection.add(pt);
  return true;
}

