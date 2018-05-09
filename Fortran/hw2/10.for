	program prob10

	integer x,tmp
	integer, external::QUANT

	do x=0,359,15
		tmp=QUANT(x*1.0)
		if(tmp==0)then
				write(*,*) "angle:",x,"   on the line, no quant"
		else
			write(*,*) "angle:",x,"   quant:",tmp
		end if
	end do

	end


	function QUANT(x)
		real::x
		integer::QUANT
		if(mod(x,90.0)==0)then
			QUANT=0
		elseif(x<=90)then
			QUANT=1
		elseif(x<=180)then
			QUANT=2
		elseif(x<=270)then
			QUANT=3
		elseif(x<360)then
			QUANT=4
		end if
		return
	end
