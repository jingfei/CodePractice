	program prob04

	integer, parameter::mmax=10000
	integer n,m,i,j
	real tmp,x(mmax),y(mmax)

	n=mmax
	do while(n>=mmax)
		write (*,*) "enter 'n' value:"
		read (*,*) n
		if(n>=mmax)then
			write (*,*) "too large"
		end if
	end do

	write (*,*) "enter n numbers x(i=1~n)"
	do i=1,n
		read (*,*) x(i)
	end do

	m=n+1
	do while(m>n)
		write (*,*) "enter 'm' value:"
		read (*,*) m
		if(m>n) then
			write (*,*) "too large"
		end if
	end do

	do i=1,n-m+1
		tmp=0.0
		do j=i,m+i-1
			tmp=tmp+x(i)
		end do
		tmp=tmp/(m*1.0)
		y(i)=tmp
		write (*,*) "y(",i,")=",y(i)
	end do 
	end

