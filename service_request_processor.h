
/* class service_request_processor*/


#ifndef __SERVICE_REQUEST_PROCESSOR_H
#define __SERVICE_REQUEST_PROCESSOR_H

#include <list>
#include "atomic.h"

class ServiceRequestProcessor : public Atomic 


{
public:
	ServiceRequestProcessor ( const string &name = "ServiceRequestProcessor" );

	

	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);
	Model &outputFunction( const InternalMessage &);

private:
	const 
	Port &srq_in;
	Port &seq_in;
	Port &sd_out;
	Port &out;
	Time service_processingTime;
	int service_type;
/*	int QoS;
	const bronze = 1; 
	const silver = 2;
	const gold = 3;
	const platinium = 4;
	const atm = 1;
	const fr = 2;
	const dsl = 3;
	const leasedline =4;
	const x25 = 5; */
	int which_port;
	double msgout;

};

inline
	string ServiceRequestProcessor::className() const
{
	return "ServiceRequestProcessor";
}
#endif 












