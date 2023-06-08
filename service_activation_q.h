
/* class service_activation_q*/


#ifndef __SERVICE_ACTIVATION_Q_H
#define __SERVICE_ACTIVATION_Q_H

#include <list>
#include "atomic.h"

class ServiceActivationQ : public Atomic 


{
public:
	ServiceActivationQ ( const string &name = "ServiceActivationQ" );

	

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
	Port &done;
	Time preparationTime;

	typedef list<Value> ElementList;
	ElementList elements;
};

inline
	string ServiceActivationQ::className() const
{
	return "ServiceActivationQ";
}
#endif 












