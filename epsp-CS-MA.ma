[top]
components : srq@ServiceRequestQ
components : seq@ServiceReadyQ
components : srp@ServiceRequestProcessor

in   : in sa_in
out  : out sd_out

Link : in in@srq
Link : sa_in in@seq
Link : out@srq srq_in@srp
Link : out@seq seq_in@srp
Link : out@srp out
Link : out@srp done@seq
Link : sd_out@srp done@srq


[srq]
preparation : 00:00:05:00

[seq]
preparation : 00:00:10:00

[srp]
processing : 00:00:05:00