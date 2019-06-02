		ORG 0000H
		
		AJMP START

		ORG 000BH ;定时器0的中断向量地址

		AJMP TIME0 ;跳转到真正的定时器程序处

		ORG 30H

START:

		
		MOV 30H,#00H ;软件计数器预清0
		
		MOV TMOD,#00000001B ;定时/计数器0工作于方式1
		
		MOV TH0, #04bH
		         
		MOV TL0, #0fdH ;初始值
		
		SETB EA ;开总中断允许
		
		SETB ET0 ;开定时/计数器0允许
		
		SETB TR0 ;定时/计数器0开始运行

		MOV A,#00H;

LOOP: 	AJMP LOOP 
	
TIME0: ;定时器0的中断处理程序
				
		INC 30H
		
		MOV R0,30H
			
		CJNE R0,#20,T_RET ;30H单元中的值是否为20

T_L1: 	

		MOV P2,A

		CPL A;
				
		MOV 30H,#0 ;清软件计数器
		
T_RET:
		
		MOV TH0,#04bH
		        
		MOV TL0,#0D7H ;重置定时常数
		
		
		RETI

DELAY:			;@11.0592MHz
		NOP
		NOP
		NOP
		PUSH 30H	  ;保护数据
		PUSH 31H
		PUSH 32H
		MOV 30H,#4
		MOV 31H,#93		;定时
		MOV 32H,#152
NEXT:
		DJNZ 32H,NEXT
		DJNZ 31H,NEXT
		DJNZ 30H,NEXT
		POP 32H
		POP 31H		  ;恢复数据
		POP 30H
		RET


END
