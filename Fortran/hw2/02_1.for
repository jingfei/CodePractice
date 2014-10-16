	program prob02_1

	integer I,J,ans1,ans2

	write (*,*) 'Enter I value:'
	read (*,*) I
	write (*,*) 'Enter J value:'
	read (*,*) J

	ans1=I-I/J*J
	ans2=MOD(I,J)

	write (*,*) 'I-I/J*J  =',ans1
	write (*,*) 'MOD(I,J) =',ans2

	if(ans1==ans2)then
		write (*,*) 'They are equal.'
	else
		write (*,*) 'They are unequal.'
	end if

	end
