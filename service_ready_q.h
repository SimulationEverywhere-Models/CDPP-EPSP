
/* class service_ready_q*/


#ifndef __SERVICE_READY_Q_H
#define __SERVICE_READY_Q_H

#include <list>
#include "atomic.h"

class ServiceReadyQ : public Atomic 


{
public:
	ServiceReadyQ ( const string &name = "ServiceReadyQ" );

	

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
	string ServiceReadyQ::className() const
{
	return "ServiceReadyQ";
}
#endif 












