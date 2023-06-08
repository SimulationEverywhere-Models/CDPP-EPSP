
#ifndef __CUSTOMER_SERVICE_H
#define __CUSTOMER_SERVICE_H

#include "atomic.h"

class CustomerService : public Atomic 


{
public:
	CustomerService ( const string &name = "CustomerService" );
	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

	Model &outputFunction( const InternalMessage &);
private:
	const Port &in;
	const Port &sa_in;
	Port &out;
	Port &sd_out;
	Time  preparationTime;
	double message;
};

inline
	string CustomerService::className() const
{
	return "CustomerService";
}
#endif 











