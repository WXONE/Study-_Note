		ORG 00H
		JMP MAIN
		ORG 03H
		JMP EXT1
		ORG 13H
		JMP EXT2
  MAIN :MOV IE,3#85H
		SETB TCON.2
		SETB TCON.0
		SJMP $
  EXT1 :MOV P2.#0
		RET1
  EXT2 :MOV P2,#0FFH
		RET1
		END