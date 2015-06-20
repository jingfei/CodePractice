#!/bin/sh

while [ "`echo $1 | cut -c1`" = "-" ]
do
	case $1 in
		-a|-b|-c)
			options="${options} $1" ;;
		*)
			echo "$1: invalid argument" ;;
	esac
	shift
done

echo "options=${options}"

