/*atomic model service_implementation_q*/

#include "service_implementation_q.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

ServiceImplementationQ::ServiceImplementationQ (const string &name)
: Atomic (name)
, in ( addInputPort("in") )
, done ( addInputPort ( "done" ) )
, out ( addOutputPort ("out") )
, preparationTime (0, 0, 5, 0) 

{
	string time(MainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &ServiceImplementationQ :: initFunction()
{ 	
	this->passivate();
	this->elements.erase(elements.begin(), elements.end() );
	return *this;
}

Model &ServiceImplementationQ::externalFunction(const ExternalMessage &msg)
{
	if ( msg.port() == in )
	{
		elements.push_back (msg.value());
		if (elements.size() == 1 )
			this->holdIn ( active, preparationTime );
	}


	if ( msg.port() == done )
	{
		elements.pop_front();
		if ( !elements.empty() )
		{
			this->holdIn ( active, preparationTime );
		}
	}

	return *this;
}

Model &ServiceImplementationQ::internalFunction ( const InternalMessage &)
{
			this->passivate();
			return *this;
}

Model &ServiceImplementationQ::outputFunction( const InternalMessage &msg)
{
	this->sendOutput ( msg.time(), out, elements.front() );
	return *this; 
}	
