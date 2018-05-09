	program prob06_2

	real, external::DETERM
	real n1,n2,n3,n4,n5,n6,n7,n8,n9
	write (*,*) "Enter 9 numbers for DETERM: "
	read (*,*) n1,n2,n3,n4,n5,n6,n7,n8,n9
	write (*,"(1x,'DETERM',A1,$)") " "
	write (*,*) DETERM(n1,n2,n3,n4,n5,n6,n7,n8,n9)
	end


	function DETERM(a,b,c,d,e,f,g,h,i)
		real::a,b,c,d,e,f,g,h,i
		real::DETERM
		DETERM=a*e*i+b*f*g+c*d*h-c*e*g-a*f*h-b*d*i
		return
	end
