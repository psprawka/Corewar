.name "zork"
.comment "just a basic living prog"
		
l2:	sti	r19,%2,%0
	and	r16 ,%2,r28
live:	live	%1  
	zjmp	%:live

