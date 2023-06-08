#include "service_implementation.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

ServiceImplementation :: ServiceImplementation(const string &name)
: Atomic (name)
, in( addInputPort("in") )
, out ( addOutputPort("out") )
, preparationTime (0, 0, 1, 0) 
{
	string time(MainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &ServiceImplementation:: initFunction()
{ 	
	message = 0;
	this->passivate();
	return *this;
}
Model &ServiceImplementation:: externalFunction( const ExternalMessage &msg)
{
	message = msg.value();
	this->sendOutput (msg.time(), out, message);
    this->holdIn ( active, preparationTime );
	return *this;
}
Model &ServiceImplementation:: internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &ServiceImplementation:: outputFunction( const InternalMessage &msg)
{
	return *this; 
}	
