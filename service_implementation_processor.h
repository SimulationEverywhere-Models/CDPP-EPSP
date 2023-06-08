
/* class service_implementation_processor*/


#ifndef __SERVICE_IMPLEMENTATION_PROCESSOR_H
#define __SERVICE_IMPLEMENTATION_PROCESSOR_H

#include <list>
#include "atomic.h"

class ServiceImplementationProcessor : public Atomic 


{
public:
	ServiceImplementationProcessor ( const string &name = "ServiceImplementationProcessor" );

	

	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);
	Model &outputFunction( const InternalMessage &);

private:
	const 
	Port &in;
	Port &out;
	Time service_processingTime;
	double msgout;

};

inline
	string ServiceImplementationProcessor::className() const
{
	return "ServiceImplementationProcessor";
}
#endif 












