	PROGRAM P8

	REAL X1,X2,X3,Y1,Y2,Y3,X,Y

	WRITE (*,*) '請輸入：'

	WRITE (*,*) '  頂點1 x座標：'
	READ (*,*) X1
	WRITE (*,*) '  頂點1 y座標：'
	READ (*,*) Y1

	WRITE (*,*) '  頂點2 x座標：'
	READ (*,*) X2
	WRITE (*,*) '  頂點2 y座標：'
	READ (*,*) Y2

	WRITE (*,*) '  頂點3 x座標：'
	READ (*,*) X3
	WRITE (*,*) '  頂點3 y座標：'
	READ (*,*) Y3

	X=(X1+X2+X3)/3.0
	Y=(Y1+Y2+Y3)/3.0
	WRITE (*,*) '重心座標為: (',X,',',Y,')'

	END

