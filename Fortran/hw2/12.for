	program prob12

	real::THETA,V,X,Y
	integer::T
	THETA=45
	V=100

	do T=0,100
		call OFFSET(THETA,V,T,X,Y)
		write(*,*) "T:",T,"  X:",X,"  Y:",Y
	end do

	end


	subroutine OFFSET(THETA,V,T,X,Y)
		real::THETA,V
		integer::T
		real::X,Y
		real::PI=3.1415926,g=9.8
		X=T*V*cos(THETA/180.0*PI)
		Y=T*V-g*T*T/2.0
		return
	end
