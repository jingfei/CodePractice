#!/bin/bash 
# Program:
#	the shell is to backup /home, /var/mail, /etc, /usr/local/etc for 3 days
# History:
# 2014/10/29	JingFei
# 2014/11/13	JingFei

DATE_none=$(date -v-3d +%Y%m%d )
DATE=$( date +%Y%m%d )

rsync -avP /home /home/jingfei/backup/

rm -rf /home/jingfei/backup/$DATE_none

mkdir /home/jingfei/backup/$DATE && cd /home/jingfei/backup/$DATE

rsync -avP /var/mail .
rsync -avP /etc .
rsync -avP /usr/local/etc local_etc
mv ../home .

scp -r ./ imslab.org:~/backup/

