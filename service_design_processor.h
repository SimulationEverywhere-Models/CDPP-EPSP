
/* class service_design_processor*/


#ifndef __SERVICE_DESIGN_PROCESSOR_H
#define __SERVICE_DESIGN_PROCESSOR_H

#include <list>
#include "atomic.h"

class ServiceDesignProcessor : public Atomic 


{
public:
	ServiceDesignProcessor ( const string &name = "ServiceDesignProcessor" );

	

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
	string ServiceDesignProcessor::className() const
{
	return "ServiceDesignProcessor";
}
#endif 












