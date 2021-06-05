
			LDR   	R0, =0xE000ED88
			LDR     R1, [R0]
			ORR     R1, R1, #(0xF << 20)
			STR     R1, [R0]
