    ORG 00H

DATA SEGMENT
     BUF DB 'WWW.nuc.edu.cn$'
DATA ENDS
START:

        MOV   SCON,#50H         //���ô��ڷ�ʽ1���������

        MOV   TMOD,#20H

        MOV   TH1, #0F3H        //������Ϊ2400B/s

        MOV   TL1, #0F3H

        SETB  TR1
SEND:

        MOV   A,   DATA
	
        MOV   P2,  A            //��ʾҪ���͵�����
        MOV   SBUF,A

WAIT:

        JBC   TI,  SEND 
        JMP   WAIT

        END