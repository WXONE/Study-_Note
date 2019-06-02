/*
实验一：外部中断实验
实验内容：设定两个外部中断1和2为边沿触发。
产生中断后，外部中断0，使LED闪烁；外部中断1使，LED流水显示。
*/
//无中断时高低四位循环亮灭
	
		ORG 0000H
		LJMP START

		ORG 0003H
		LJMP X0_INT

		ORG 0013H
		LJMP X1_INT

		ORG 0030H

START:				  ;初始化
		SETB IT0	  ;外部中断0 跳变沿触发
		SETB IT1	  ;外部中断1 跳变沿触发
		SETB EX0	  ;打开外部中断0
		SETB EX1	  ;打开外部中断1
		SETB EA
		MOV SP,#50H	  ;堆栈指针	初始位置50H，
		MOV A,#0F0H	  ;F0H送给A

LOOP:	MOV P1,A	   ;A传送给P1。P1输出值给led灯
		CALL DELAY	   ;延时
		CPL A		   ;取反
		
		SJMP LOOP	   ;循环，等待中断

X0_INT:
		PUSH ACC	   ;保护数据
	   	PUSH PSW	
		MOV A,#0FFH 	;全灭
		MOV R2, #4	  	;亮灭共四次

X0_1:
		MOV P1,A		;P1输出
		CALL DELAY		;延时
		CPL A		  	;取反，全亮或全灭
		DJNZ R2,X0_1  	;判断R2是否为零并自减，跳转
		POP PSW			;取出数据
		POP ACC
		RETI			;中断返回

X1_INT:
		PUSH ACC
		PUSH PSW
		SETB RS1
		MOV A,#0FEH
		MOV R2,#8	   ;流水灯亮8次

X1_1:
		MOV P1,A
		CALL DELAY
		RL A
		DJNZ R2,X1_1
		POP PSW
		POP ACC
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




