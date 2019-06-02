    ORG 00H

DATA SEGMENT
     BUF DB 'WWW.nuc.edu.cn$'
DATA ENDS
START:

        MOV   SCON,#50H         //设置串口方式1，允许接受

        MOV   TMOD,#20H

        MOV   TH1, #0F3H        //波特率为2400B/s

        MOV   TL1, #0F3H

        SETB  TR1
SEND:

        MOV   A,   DATA
	
        MOV   P2,  A            //显示要发送的数据
        MOV   SBUF,A

WAIT:

        JBC   TI,  SEND 
        JMP   WAIT

        END