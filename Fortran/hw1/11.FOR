	PROGRAM P11

	REAL P,i,q
	INTEGER year,n

	WRITE (*,*) 'enter ''P'' value:'
	READ (*,*) P

	WRITE (*,*) 'enter ''i'' value:'
	READ (*,*) i

	WRITE (*,*) 'enter ''q'' value:'
	READ (*,*) q

	WRITE (*,*) 'enter ''n'' value:'
	READ (*,*) n

	DO 10 year=1,n
		WRITE (*,*) year,'year:', P*(1+i/q)**(year*q)
10	CONTINUE

	END
