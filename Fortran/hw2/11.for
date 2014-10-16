	program prob11

	real A,B,C,R,ANGA,ANGB,ANGC
	logical ANS,ERROR
	write(*,*) "enter 'A' value"
	read (*,*) A
	write(*,*) "enter 'B' value"
	read (*,*) B
	write(*,*) "enter 'C' value"
	read (*,*) C

	call ANGLES(A,B,C,ANGA,ANGB,ANGC,ERROR)
	call RIGHT(A,B,C,R,ANS)

	write(*,*) "ANS:  ",ANS,"R:   ",R
	write(*,*) "ERROR:",ERROR,"ANGA:",ANGA,"ANGB:",ANGB,"ANGC:",ANGC

	end


	subroutine RIGHT(A,B,C,R,ANS)
		real::A,B,C,R
		logical::ANS
		real tmp

		if(A>C)then
			tmp=A
			A=C
			C=tmp
		end if

		if(B>C)then
			tmp=B
			B=C
			C=tmp
		end if

		if(A*A+B*B<C*C+0.01 .and. A*A+B*B>C*C-0.01)then
			ANS=.true.
			R=C
		else
			ANS=.false.
			R=0
		end if

		return
	end


	subroutine ANGLES(A,B,C,ANGA,ANGB,ANGC,ERROR)
		real::A,B,C,ANGA,ANGB,ANGC
		logical::ERROR
		real::PI=3.1415926

		if(A+B>C .and. A-B<C .and. B-A<C)then
			ERROR=.false.
		else
			ERROR=.true.
		end if

		if(ERROR .eqv. .false.)then
			ANGA=acos((B*B+C*C-A*A)/(2*B*C))/PI*180
			ANGB=acos((A*A+C*C-B*B)/(2*A*C))/PI*180
			ANGC=acos((A*A+B*B-C*C)/(2*A*B))/PI*180
		end if

		return
	end
