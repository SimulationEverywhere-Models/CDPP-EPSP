[top]
components : saq@ServiceActivationQ
components : sap@ServiceActivationProcessor
in   : in done
out  : out

Link : in in@saq
Link : out@saq in@sap
Link : out@sap out
Link : out@sap done@saq


[sap]
processing : 00:00:05:00

[saq]
preparation : 00:00:05:00
