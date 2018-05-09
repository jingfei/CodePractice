	program prob1

	integer A,B,C,tmp

	write (*,*) "Enter A value:"
	read (*,*) A

	write (*,*) "Enter B value:"
	read (*,*) B

	write (*,*) "Enter C value:"
	read (*,*) C

	if(A>B)then
		tmp=A
		A=B
		B=tmp
	end if

	if(A>C)then
		tmp=A
		A=B
		B=tmp
	end if

	if(B>C)then
		tmp=B
		B=C
		C=tmp
	end if

	if(A==B .and. B==C)then
		write (*,*) '等邊三角形'
	else if(A==B .and. A*A*2==C)then
		write (*,*) '等腰直角三角形'
	else if(A==B .or. B==C)then
		write (*,*) '等腰三角形'
	else if(A*A+B*B==C*C)then
		write (*,*) '直角三角形'
	else
		write (*,*) '非特殊三角形'
	end if

	end
