[top]
components : CustomerService
components : ServiceDesign
components : ServiceImplementation
components : ServiceActivation

in  : in 
out : out

Link : in in@CustomerService
Link : out@CustomerService out
Link : sd_out@CustomerService in@ServiceDesign
Link : out@ServiceDesign in@ServiceImplementation
Link : out@ServiceImplementation in@ServiceActivation
Link : out@ServiceActivation sa_in@CustomerService

[CustomerService]
components : srq@ServiceRequestQ
components : seq@ServiceReadyQ
components : srp@ServiceRequestProcessor

in   : in sa_in
out  : out sd_out

Link : in in@srq
Link : sa_in in@seq
Link : out@srq srq_in@srp
Link : out@seq seq_in@srp
LInk : out@srp out
Link : sd_out@srp in@ServiceDesign


[ServiceDesign]
components : sdq@ServiceDesignQ
components : sdp@ServiceDesignProcessor
in   : in done
out  : out

Link : in in@sdq
Link : out@sdq in@sdp
Link : out@sdp done@sdq
Link : out@sdp in@ServiceImplementation


[ServiceImplementation]
components : siq@ServiceImplementationQ
components : sip@ServiceImplementationProcessor

in   : in done
out  : out

Link : in in@siq
Link : out@siq in@sip
Link : out@sip done@siq
Link : out@sip in@ServiceActivation


[ServiceActivation]
components : saq@ServiceActivationQ
components : sap@ServiceActivationProcessor
in   : in done
out  : out

Link : in in@saq
Link : out@saq in@sap
Link : out@sap done@saq
Link : out@sap sa_in@CustomerService


[srq]
preparation : 00:00:05:00

[seq]
preparation : 00:00:10:00

[srp]
processing : 00:00:05:00

[sdp]
processing : 00:00:05:00

[sdq]
preparation : 00:00:05:00

[sip]
processing : 00:00:05:00

[siq]
preparation : 00:00:05:00

[sap]
processing : 00:00:05:00

[saq]
preparation : 00:00:05:00
