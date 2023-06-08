
/* class service_implementation_q*/


#ifndef __SERVICE_IMPLEMENTATION_Q_H
#define __SERVICE_IMPLEMENTATION_Q_H

#include <list>
#include "atomic.h"

class ServiceImplementationQ : public Atomic 


{
public:
	ServiceImplementationQ ( const string &name = "ServiceImplementationQ" );

	

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
	string ServiceImplementationQ::className() const
{
	return "ServiceImplementationQ";
}
#endif 












