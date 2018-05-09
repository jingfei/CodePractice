	PROGRAM P15

	REAL X,Y
	LOGICAL ANS

	WRITE (*,*) 'enter x value:'
	READ (*,*) X

	WRITE (*,*) 'enter y value:'
	READ (*,*) Y

	IF (Y .GE. 3) THEN
		ANS=.FALSE.
	ELSE IF (X+Y .LE. 1) THEN
		ANS=.FALSE.
	ELSE IF (Y .GE. 2*X+1) THEN
		ANS=.FALSE.
	ELSE IF (Y .LE. X*X) THEN
		ANS=.FALSE.
	ELSE
		ANS=.TRUE.
	END IF

c	WRITE (*,*) ANS
	IF (ANS .EQV. .TRUE.) THEN
   		WRITE (*,*) 'YES'
	ELSE
		WRITE (*,*) 'NO'
	END IF

	END
