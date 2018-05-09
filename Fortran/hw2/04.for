	program prob04

	real,external::func
	real::a=-2.0,b=2.0
	real c
	do while(func(a)*func(b)<0)
		c=(a+b)/2.0
		if(func(c)>-0.0000001 .and. func(c)<0.0000001) exit
		if(func(c)*func(a)<0)then
			b=c
		else
			a=c
		end if
	end do
	write (*,'(1x,f13.10)') c
	end

	function func(x)
		real::x
		real::func
		real,parameter::pi=3.1415926,a=0.8475
		func=sqrt(pi/2.0)*exp(a*x)+x/(a*a+x*x)
		return
	end
