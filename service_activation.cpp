#include "service_activation.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

ServiceActivation :: ServiceActivation(const string &name)
: Atomic (name)
, in( addInputPort("in") )
, out ( addOutputPort("out") )
, preparationTime (0, 0, 1, 0) 
{
	string time(MainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &ServiceActivation:: initFunction()
{ 	
	message = 0;
	this->passivate();
	return *this;
}
Model &ServiceActivation:: externalFunction( const ExternalMessage &msg)
{
	message = msg.value();
	this->sendOutput (msg.time(), out, message);
  	this->holdIn ( active, preparationTime );
	return *this;
}
Model &ServiceActivation:: internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &ServiceActivation:: outputFunction( const InternalMessage &msg)
{
	return *this; 
}	
