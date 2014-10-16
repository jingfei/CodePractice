	program prob08

	real, external::PI
	integer n

	write (*,*) "enter integer 'n' value:"
	read (*,*) n

	write(*,*) "PI:", PI(n)
	write(*,*) "arc cos(-1):", acos(-1.0)

	end


	function PI(n)
		integer::n
		real::PI
		real::tmp=0.0
		integer i
		do i=1,n
			tmp=tmp+(1.0/(i*i*1.0))
		end do
		PI=sqrt(tmp*6)
		return
	end
