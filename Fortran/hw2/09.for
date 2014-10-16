	program prob09

	integer n
	integer, external::RNDM

	write (*,*) "enter an integer with four digits"
	read (*,*) n

	write (*,*) "Before:", n
	write (*,*) "After: ", RNDM(n)

	end


	function RNDM(n)
		integer::n
		integer::RNDM
		integer ans,tmp
		ans=n*n/100
		tmp=ans/10000*10000
		RNDM=ans-tmp
		return
	end
