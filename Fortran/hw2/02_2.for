	program prob02_2

	integer Y
	logical Leap

	write (*,*) 'Enter Y value:'
	read (*,*) Y

	if(Y/400*400==Y)then
		Leap=.true.
	else if(Y/100*100==Y)then
		Leap=.false.
	else if(Y/4*4==Y)then
		Leap=.true.
	else
		Leap=.false.
	end if

	if(Leap .eqv. .true.)then
		write (*,*) '366 days'
	else
		write (*,*) '365 days'
	end if

	end
