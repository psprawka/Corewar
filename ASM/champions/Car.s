#deassembler par msa 1.8, made by joe
.name "Tching tching(Intercepteur), Bouh!Bouh!(bruits d'anti-jeu)"
.comment ""

	 ld    %-272,r3           		# 7,3,278
	 live  %0                 		# 5,10,271
	 fork  %:label01          		# 3,15,266
	 ld    %-272,r3           		# 7,18,263
	 fork  %:label02          		# 3,25,256
	 ld    %0,r2              		# 7,28,253
	 ld    %0,r4              		# 7,35,246
	 zjmp  %:label03          		# 3,42,239

label02: ld    %4,r2              		# 7,45,236
	 ld    %0,r4              		# 7,52,229
	 zjmp  %:label03          		# 3,59,222

label01: ld    %-202,r3           		# 7,62,219
	 fork  %:label04          		# 3,69,212
	 ld    %0,r2              		# 7,72,209
	 ld    %0,r4              		# 7,79,202
	 zjmp  %:label05          		# 3,86,195

label04: ld    %4,r2              		# 7,89,192
	 ld    %0,r4              		# 7,96,185

label12: ld    %4,r2              		# 7,141,140
	 ld    %0,r4              		# 7,148,133
	 zjmp  %:label08          		# 3,155,126

label03: ldi   r2,%:label12,r6    		# 6,181,100
	 ld    %0,r4              		# 7,187,94
	 live  %1                 		# 5,194,87

label08: ldi   r2,%:label13,r6    		# 6,207,74
	 ld    %0,r4              		# 7,213,68
	 live  %1                 		# 5,220,61

label13: sti   r6,r2,r3           		# 5,225,56
	 zjmp  %395               		# 3,230,51

label05: ldi   r2,%:label14,r6    		# 6,233,48
	 ld    %0,r4              		# 7,239,42
	 live  %1                 		# 5,246,35

label14: sti   r6,r2,r3           		# 5,251,30
	 zjmp  %-207              		# 3,256,25

