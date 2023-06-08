/*atomic model service_design_processor*/

#include "service_design_processor.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

ServiceDesignProcessor::ServiceDesignProcessor (const string &name)
: Atomic (name)
, in( addInputPort("in") )
, out ( addOutputPort("out") )

, service_processingTime (0, 0, 5, 0) 
{
	string time(MainSimulator::Instance().getParameter(description(), "processing"));
	if (time!=" ")
		service_processingTime = time;
}

Model &ServiceDesignProcessor :: initFunction()
{ 	
	this->passivate();
	return *this;
}

Model &ServiceDesignProcessor::externalFunction( const ExternalMessage &msg)
{
	
	msgout = msg.value();
	this->holdIn ( active, service_processingTime );
	return *this;

}


Model &ServiceDesignProcessor::internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &ServiceDesignProcessor::outputFunction( const InternalMessage &msg)
{
	this->sendOutput ( msg.time(), out, msgout);
	return *this; 
}	
