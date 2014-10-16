	PROGRAM P9

	REAL a,d,an,sn
	INTEGER n

	WRITE (*,*) 'enter ''a'' value:'
	READ (*,*) a

	WRITE (*,*) 'enter ''d'' value:'
	READ (*,*) d

	WRITE (*,*) 'enter ''n'' value:'
	READ (*,*) n

	an=a+(n-1)*d
	sn=n*(2*a+(n-1)*d)/2.0

	WRITE (*,*) '第',n,'項    ：',an
	WRITE (*,*) '前',n,'項總合：',sn

	END
