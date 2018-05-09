	PROGRAM P13

	REAL L,a,b,PI,ANS
	PARAMETER (PI=3.1415926)

	WRITE (*,*) 'enter ''L'' value:'
	READ (*,*) L

	WRITE (*,*) 'enter ''alpha'' value:'
	READ (*,*) a

	WRITE (*,*) 'enter ''beta'' value:'
	READ (*,*) b

	a=TAN(a/180*PI)
	b=TAN(b/180*PI)
	ANS=L/(1/a+1/b)

	WRITE (*,*) 'Height:',ANS

	END
