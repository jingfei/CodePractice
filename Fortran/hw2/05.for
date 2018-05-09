	program prob05

	integer n,div,limit,times
	logical first

	write (*,*) "Please enter n value"
	read (*,*) n
	first=.true.
	write (*,'(1x,I5,A6,$)') n,"     ="

	do div=2,n
		times=0
		do while(n/div*div==n)
			times=times+1
			n=n/div
		end do
		if(times>0)then
			if(first .neqv. .true.)then
				write (*,'(1x,A5,$)') "    *"
			else
				first=.false.
			end if
			if(times==1)then
				write (*,'(1x,I5,$)') div
			else
				write (*,'(1x,I5,A4,I3,$)') div,"   ^",times
			end if
		end if
		if(n==1) exit
	end do
	if(first .eqv. .true.)then
		write(*,'(1x,I5)') n
	end if
	write (*,*) " "
	end
