
/* class service_request_q*/


#ifndef __SERVICE_REQUEST_Q_H
#define __SERVICE_REQUEST_Q_H

#include <list>
#include "atomic.h"

class ServiceRequestQ : public Atomic 


{
public:
	ServiceRequestQ ( const string &name = "ServiceRequestQ" );

	

	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);
	Model &outputFunction( const InternalMessage &);

private:
	const 
	Port &in;
	Port &done;
	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList;
	ElementList elements;
};

inline
	string ServiceRequestQ::className() const
{
	return "ServiceRequestQ";
}
#endif 












