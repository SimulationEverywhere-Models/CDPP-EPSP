#ifndef __SERVICE_ACTIVATION_PROCESSOR_H
#define __SERVICE_ACTIVATION_PROCESSOR_H

#include <list>
#include "atomic.h"

class ServiceActivationProcessor : public Atomic 


{
public:
	ServiceActivationProcessor ( const string &name = "ServiceActivationProcessor" );

	

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
	string ServiceActivationProcessor::className() const
{
	return "ServiceActivationProcessor";
}
#endif 












