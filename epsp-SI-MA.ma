[top]
components : siq@ServiceImplementationQ
components : sip@ServiceImplementationProcessor

in   : in done
out  : out

Link : in in@siq
Link : out@siq in@sip
Link : out@sip out
Link : out@sip done@siq


[sip]
processing : 00:00:05:00

[siq]
preparation : 00:00:05:00

