#include "customer_service.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

CustomerService :: CustomerService(const string &name)
: Atomic (name)
, in( addInputPort("in") )
, sa_in( addInputPort("sa_in") )
, out ( addOutputPort("out") )
, sd_out( addInputPort("sd_out") )
, preparationTime (0, 0, 5, 0)
{
	string time(MainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &CustomerService:: initFunction()
{
	message = 0;
	this->passivate();
	return *this;
}
Model &CustomerService:: externalFunction( const ExternalMessage &msg)
{
	message = msg.value();
	if(msg.port() == in)
		this->sendOutput (msg.time(), sd_out, message);
	if(msg.port() == sa_in)
		this->sendOutput (msg.time(), out, message);
       	this->holdIn ( active, preparationTime );
	return *this;
}
Model &CustomerService:: internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &CustomerService:: outputFunction( const InternalMessage &msg)
{
	return *this;
}
