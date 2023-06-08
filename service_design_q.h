
/* class service_design_q*/


#ifndef __SERVICE_DESIGN_Q_H
#define __SERVICE_DESIGN_H

#include <list>
#include "atomic.h"

class ServiceDesignQ : public Atomic 


{
public:
	ServiceDesignQ ( const string &name = "ServiceDesignQ" );

	

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
	string ServiceDesignQ::className() const
{
	return "ServiceDesignQ";
}
#endif 












