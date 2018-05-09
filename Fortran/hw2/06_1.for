	program prob06_1

	real a,b,c,tmp
	real, external::D
	real, external::Ans1
	real, external::Ans2
	write (*,*) "enter 'a' value:"
	read (*,*) a
	write (*,*) "enter 'b' value:"
	read (*,*) b
	write (*,*) "enter 'c' value:"
	read (*,*) c

	tmp=D(a,b,c)
	if(tmp<0)then
		write (*,*) "no answer"
	else
		write (*,*) "first  root:", Ans1(tmp,a,b)
		write (*,*) "second root:", Ans2(tmp,a,b)
	end if

	end

	function D(a,b,c)
		real::a,b,c
		real::D
		D=b*b-4*a*c
		return
	end

	function Ans1(x,a,b)
		real::x,a,b
		real::Ans1
		Ans1=(b*(-1)+sqrt(x))/(2*a)
		return
	end

	function Ans2(x,a,b)
		real::x,a,b
		real::Ans2
		Ans2=(b*(-1)-sqrt(x))/(2*a)
		return
	end

