/************** Service Activation Processor ********************************
*																			*
*	This model is responsible for activating services.						*
*	It receives requests for activation from service implementation			*
*	processor. The service Activation requests are queued as they arrive	*
*																		    *
****************************************************************************/

#include "service_activation_processor.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

ServiceActivationProcessor::ServiceActivationProcessor (const string &name)
: Atomic (name)
, in( addInputPort("in") )
, out ( addOutputPort("out") )

{
	string time(MainSimulator::Instance().getParameter(description(), "processing"));
	if (time!=" ")
		service_processingTime = time;
}

Model &ServiceActivationProcessor :: initFunction()
{ 	
	this->passivate();
	return *this;
}

Model &ServiceActivationProcessor::externalFunction( const ExternalMessage &msg)
{
	msgout = msg.value();
	this->holdIn ( active, service_processingTime );
	return *this;

}


Model &ServiceActivationProcessor::internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}

Model &ServiceActivationProcessor::outputFunction( const InternalMessage &msg)
{
	this->sendOutput ( msg.time(), out, msgout );
	return *this; 
}	
