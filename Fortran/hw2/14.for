	program prob14

	real::H,VA,A,V,VT,T
	logical::HIT

	H=1000
	A=0
	VA=2000
	V=950
	call MISSLE(H,VA,A,V,VT,T,HIT)
	write (*,*) "HIT?",HIT

	H=1400
	A=30
	VA=600
	V=950
	call MISSLE(H,VA,A,V,VT,T,HIT)
	write (*,*) "HIT?",HIT

	end


	subroutine MISSLE(H,VA,A,V,VT,T,HIT)
		real::H,VA,A,V,VT,T
		logical::HIT
		VT=acos(VA*cos(A)/V)
		T=H/(V*sin(VT)-VA*sin(A))
		if(VT<-1 .or. VT>1)then
			HIT=.false.
		else if(T>10.0)then
			HIT=.false.
		else if(VT<20 .or. VT>70)then
			HIT=.false.
		else
			HIT=.true.
		end if
		write (*,10) "H:",H,"A:",A,"VA:",VA,"V:",V
10		format (1x,a4,f8.2,a4,f8.2,a5,f8.2,a4,f8.2)
		return
	end

