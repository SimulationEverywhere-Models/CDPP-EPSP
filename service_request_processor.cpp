/*atomic model service_request_processor*/

#include "service_request_processor.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

ServiceRequestProcessor::ServiceRequestProcessor (const string &name)
: Atomic (name)
, srq_in( addInputPort("srq_in") )
, seq_in( addInputPort("seq_in") )
, sd_out ( addOutputPort("sd_out") )
, out ( addOutputPort("out") )
, service_processingTime (0, 0, 5, 0) 
{
/*	string time(MainSimulator::Instance().getParameter(description(), "processing"));
	if (time!=" ")
		service_processingTime = time;*/
 
}

Model &ServiceRequestProcessor :: initFunction()
{ 	
	this->passivate();
	return *this;
}

Model &ServiceRequestProcessor::externalFunction( const ExternalMessage &msg)
{
	msgout = msg.value ();
	if ( msg.port() == srq_in )
	{    // a new service request arrived
		// process the request and create a service requirement description - srd
		which_port = 1; // srq_in port
		this->holdIn ( active, service_processingTime);
	}

	if ( msg.port() == seq_in )
	{   // previous service request was activated
		// start billing
		// inform customer
		// send done to SRO
		which_port = 2; // seq_in port
		this->holdIn ( active, service_processingTime );

	}

	return *this;

}


Model &ServiceRequestProcessor::internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}

Model &ServiceRequestProcessor::outputFunction( const InternalMessage &msg)
{
	// send  srd to sd_out
	// send done to SRI
	if (which_port == 1)
			this->sendOutput ( msg.time(), sd_out, msgout);
	else
			this->sendOutput ( msg.time(), out, msgout);

	return *this; 
}	

// determine_time (...)

/*Time ServiceRequestProcessor::determine_time(const InternalMessage &msg)
{
**********************************************************************
*	This function is supposed to determine the time necessary to     *
*	process the service description. The calculation is dependant    *
*	from several factors such as:									 *
*		- the number of people involved								 *
*		- the tools used (computers, etc.)							 *
*		- the manual tasks used										 *
*		- external resources used									 *
*		- Etc.														 *
*																	 *
* In order to properly determine the service processing time, the    *
* above factors should be linked together in some FORMULA. It is     *
* key to know the formula in order to create variations in these     *
* factors and thus determine the optimal configuration.              *
* Since we don't have such formula, then it is not possible to       *
* implement this formula in a precise way.                           *
*																	 *
* We will assume thereby the following:								 *
*																	 *
* We have five data services: ATM, FR, DSL, DDL, X25				 *
*																	 *
* Each Service will take some time to fully describe it				 *
* The Determine_time function will return a constant value			 *
* depending on the type of service we have to provision.			 *
* As said above, in reality, it is much more complex and it should   *
* take a formula to do it.											 *
*																	 *
**********************************************************************

  case msg.value():
		X25: return (0, 0, 5, 0);
		DDL: return (0, 0, 10, 0);		
		DSL: return (0, 0, 15, 0);
		FR : return (0, 0, 20, 0);
		ATM: return (0, 0, 25, 0);
}*/
