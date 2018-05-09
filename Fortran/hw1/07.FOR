	PROGRAM P7

	REAL a,b,c,s,AREA

	WRITE (*,*) 'Please enter ''a'' value: '
	READ (*,*) a

	WRITE (*,*) 'Please enter ''b'' value: '
	READ (*,*) b

	WRITE (*,*) 'Please enter ''c'' value: '
	READ (*,*) c

	s=(a+b+c)/2.0
	AREA=(s*(s-a)*(s-b)*(s-c))**0.5
c	WRITE (*,*) 's = ',s
	WRITE (*,*) 'AREA   =', AREA

	END

