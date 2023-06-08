/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "queue.h"      // class Queue
#include "generat.h"    // class Generator
#include "cpu.h"        // class CPU
#include "transduc.h"   // class Transducer
#include "trafico.h"    // class Trafico
#include "service_request_q.h" // class customer_service
#include "service_ready_q.h" // class customer_service
#include "service_request_processor.h" // class customer_service
#include "service_design_q.h" //class service_design
#include "service_design_processor.h" //class service_design
#include "service_implementation_q.h" // class service_implementation
#include "service_implementation_processor.h" // class service_implementation
#include "service_activation_q.h" //class service_activation
#include "service_activation_processor.h" //class service_activation
#include "customer_service.h"
#include "service_design.h"
#include "service_implementation.h"
#include "service_activation.h"

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trafico>() , "Trafico" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceRequestQ>() , "ServiceRequestQ" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceReadyQ>() , "ServiceReadyQ" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceRequestProcessor>() , "ServiceRequestProcessor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceDesignQ>() , "ServiceDesignQ" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceDesignProcessor>() , "ServiceDesignProcessor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceImplementationQ>() , "ServiceImplementationQ" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceImplementationProcessor>() , "ServiceImplementationProcessor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceActivationQ>() , "ServiceActivationQ" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceActivationProcessor>() , "ServiceActivationProcessor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CustomerService>() , "CustomerService" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceImplementation>() , "ServiceImplementation" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceActivation>() , "ServiceActivation" ) ;

}

