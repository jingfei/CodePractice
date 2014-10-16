	program prob13

	integer D,MM,DD,YY

	write (*,*) "enter 'D' value:"
	read (*,*) D

	call CONVRT(D,MM,DD,YY)
	write (*,100) "year:",YY,"   month:",MM,"   day:",DD
100	format (1x,A6,I5,A9,I3,A7,I3)

	end


	subroutine CONVRT(D,MM,DD,YY)
		integer::D,MM,DD,YY
		YY=D/10000
		MM=(D-YY*10000)/100
		DD=D-YY*10000-MM*100
		return
	end
