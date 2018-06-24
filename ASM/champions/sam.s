.name "zork"
.comment "just a basic living prog"

fork %-30
ld    %6, r2
l2:    st    r1, r2
    and    r1,%0,r1
live:    live    %1
    zjmp    %:live
