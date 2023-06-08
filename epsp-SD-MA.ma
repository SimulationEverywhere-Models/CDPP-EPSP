[top]
components : sdq@ServiceDesignQ
components : sdp@ServiceDesignProcessor
in   : in done
out  : out

Link : in in@sdq
Link : out@sdq in@sdp
Link : out@sdp out
Link : out@sdp done@sdq

[sdp]
processing : 00:00:05:00

[sdq]
preparation : 00:00:05:00

