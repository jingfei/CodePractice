	PROGRAM P12

	INTEGER X,i
	REAL c1,c2,c3,ANS,tmp,ANS2
	PARAMETER (c1=0.8690286, c2=0.2773829, c3=0.2543275,X=10)

	DO 10 i=1,X
		tmp=(i-10**0.5)/(i+10**0.5)
		ANS=0.5+c1*tmp+c2*tmp**3+c3*tmp**5
		ANS2=LOG10(i*1.0)
		WRITE (*,*) 'X        =',i
		WRITE (*,*) 'COMPUTED =',ANS
		WRITE (*,*) 'LOG10(X) =',ANS2
		WRITE (*,*) 'ERROR    =',ABS(ANS-ANS2)
		WRITE (*,*) ' '
10	CONTINUE

	END
