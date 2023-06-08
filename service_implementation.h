
#ifndef __SERVICE_IMPLEMENTATION_H
#define __SERVICE_IMPLEMENTATION_H

#include "atomic.h"

class ServiceImplementation : public Atomic 


{
public:
	ServiceImplementation ( const string &name = "CustomerService" );
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
	string ServiceImplementation::className() const
{
	return "ServiceImplementation";
}
#endif 











