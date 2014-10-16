	PROGRAM P14

	REAL a,b,c,tmp

	WRITE (*,*) 'enter one value of the edge:'
	READ (*,*) a

	WRITE (*,*) 'enter the other:'
	READ (*,*) b

	WRITE (*,*) 'enter another:'
	READ (*,*) c

	IF (a .GT. b) THEN
		tmp=a
		a=b
		b=tmp
	END IF

	IF (a .GT. c) THEN
		tmp=a
		a=c
		c=tmp
	END IF

	IF (b .GT. c) THEN
		tmp=b
		b=c
		c=tmp
	END IF

	IF (a*a+b*b .EQ. c*c) THEN
		WRITE (*,*) 'This is a RIGHT TRIANGLE'
		WRITE (*,*) 'Hypotenuse is',c
	ELSE
		WRITE (*,*) 'This is not a RIGHT TRIANGLE!!'
	END IF

	END
