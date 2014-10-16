	program prob03

	integer S,E,N,D,M,O,Y,R
	integer tmp

	do D=0,9
	do E=0,9
	if(E==D) cycle
	do Y=0,9
	if(Y==D .or. Y==E) cycle
	do N=0,9
	if(N==E .or. N==D .or. N==Y)cycle
	do R=0,9
	if(R==E .or. R==D .or. R==N .or. R==Y)cycle
	do O=0,9
	if(O==E .or. O==D .or. O==N .or. O==Y .or. O==R)cycle
	do M=1,9
	if(M==E .or. M==D .or. M==N .or. M==Y .or. M==R .or. M==O)cycle
	do S=1,9
	if(S==E.or.S==D.or.S==N.or.S==Y.or.S==R.or.S==O.or.S==M)cycle
		tmp=S*1000+E*100+N*10+D+M*1000+O*100+R*10+E
		if(tmp==M*10000+O*1000+N*100+E*10+Y) then
			write (*,200) S,E,N,D,'+',M,O,R,E,'=',M,O,N,E,Y
200			format (1x,i1,i1,i1,i1,a1,i1,i1,i1,i1,a1,i1,i1,i1,i1,i1);
		end if
	end do
	end do
	end do
	end do
	end do
	end do
	end do
	end do

	end
