	program prob07

	integer n
	real, external::EULER

	write(*,*) "enter integer 'n' value:"
	read (*,*) n

	if(n<=0)then
		write(*,*) "n should be larger than 0"
	else
		write(*,*) "Euler:",EULER(n)
	end if

	end


	function EULER(n)
		integer::n
		real::EULER
		real::tmp=0.0
		integer i
		do i=1, n
			tmp=tmp+(1.0/(i*1.0))
		end do
		EULER=log(n*1.0)-tmp
		return
	end
