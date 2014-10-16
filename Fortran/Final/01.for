	program prob1

	integer, external::Lucas
	integer n

	write (*,*) "enter 'n' value:"
	read (*,*) n

	write (*,*) "Lucas",n,"=",Lucas(n)
	end


	recursive integer function Lucas(n)result(ans)
		integer,intent(in)::n

		if(n==1)then
			ans=1
		else if(n==2)then
			ans=3
		else
			ans=Lucas(n-1)+Lucas(n-2)
		end if
		return
	end

