#include "service_design.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

ServiceDesign :: ServiceDesign(const string &name)
: Atomic (name)
, in( addInputPort("in") )
, out ( addOutputPort("out") )
, preparationTime (0, 0, 1, 0) 

{
	string time(MainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &ServiceDesign:: initFunction()
{ 	
	message = 0;
	this->passivate();
	return *this;
}

Model &ServiceDesign:: externalFunction( const ExternalMessage &msg)
{
	message = msg.value();
	this->sendOutput (msg.time(), out, message);
	return *this;
}

Model &ServiceDesign:: internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}

Model &ServiceDesign:: outputFunction( const InternalMessage &msg)
{
	return *this; 
}	
