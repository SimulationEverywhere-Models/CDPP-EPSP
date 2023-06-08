
#ifndef __SERVICE_ACTIVATION_H
#define __SERVICE_ACTIVATION_H

#include "atomic.h"

class ServiceActivation : public Atomic 


{
public:
	ServiceActivation ( const string &name = "CustomerService" );
	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

	Model &outputFunction( const InternalMessage &);
private:
	const Port &in;
	Port &out;
	Time  preparationTime;
	double message;
};

inline
	string ServiceActivation::className() const
{
	return "ServiceActivation";
}
#endif 











