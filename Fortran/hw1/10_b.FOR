	PROGRAM P10_B

	REAL a,b,c,d,e,f,X,Y,tmp

	WRITE (*,*) 'enter ''a'' value:'
	READ (*,*) a

	WRITE (*,*) 'enter ''b'' value:'
	READ (*,*) b

	WRITE (*,*) 'enter ''c'' value:'
	READ (*,*) c

	WRITE (*,*) 'enter ''d'' value:'
	READ (*,*) d

	WRITE (*,*) 'enter ''e'' value:'
	READ (*,*) e

	WRITE (*,*) 'enter ''f'' value:'
	READ (*,*) f

	X=(c*e-b*f)/(a*e-b*d)
	Y=(a*f-c*d)/(a*e-b*d)
	tmp=a*e-b*d

	IF (tmp .EQ. 0.0 .AND. c/b .EQ. f/e) THEN
		WRITE (*,*) 'Infinite Solution!'
	ELSE IF (tmp .EQ. 0.0) THEN 
		WRITE (*,*) 'No Solution!'
	ELSE
		WRITE (*,*) 'Solution of'
		WRITE (*,*) a,'x +',b,'y =',c
		WRITE (*,*) d,'x +',e,'y =',f
		WRITE (*,*) '(x,y) is (',X,',',Y,')'
	END IF

	END
