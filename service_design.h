
#ifndef __SERVICE_DESIGN_H
#define __SERVICE_DESIGN_H

#include "atomic.h"

class ServiceDesign: public Atomic 


{
public:
	ServiceDesign ( const string &name = "ServiceDesign" );
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
	string ServiceDesign::className() const
{
	return "ServiceDesign";
}
#endif 











