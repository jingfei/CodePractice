	PROGRAM CIRCLE

	REAL PI
	INTEGER R,LOW,HIGH,STEP
	PARAMETER (PI=3.1415926)

	WRITE (*,*) 'LOW VALUE:'
	READ (*,*) LOW

	WRITE (*,*) 'GIGH VALUE:'
	READ (*,*) HIGH

	WRITE (*,*) 'STEP VALUE:'
	READ (*,*) STEP

	DO 10 R=LOW,HIGH,STEP
		WRITE (*,'(1X,F8.0,F10.2)') R,R*2*PI
10 	CONTINUE

	END


