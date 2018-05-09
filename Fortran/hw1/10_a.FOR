	PROGRAM P10_A

	REAL a,b,c,d,dis

	WRITE (*,*) 'enter ''a'' value:'
	READ (*,*) a

	WRITE (*,*) 'enter ''b'' value:'
	READ (*,*) b

	WRITE (*,*) 'enter ''c'' value:'
	READ (*,*) c

	WRITE (*,*) 'enter ''d'' value:'
	READ (*,*) d

	dis=((a-c)*(a-c)+(b-d)*(b-d))**0.5
	WRITE (*,*) 'distance:',dis

	END
