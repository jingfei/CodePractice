#!/bin/bash
# Program:
#	the shell is for login file everyday
# History:
# 2014/10/29	JingFei

DATE_none=$(date -v-3d +%Y%m%d )
DATE=$( date +%Y%m%d )
Yesterday=$(date -v-1d +$d )


rsync -avP /home /home/jingfei/backup/

rm -rf /home/jingfei/backup/$DATE_none

mkdir /home/jingfei/backup/$DATE && cd /home/jingfei/backup/$DATE

rsync -avP /var/mail .
rsync -avP /etc .
rsync -avP /usr/local/etc local_etc
mv ../home .

mkdir logs && cd logs
awk '{ if($5 ~ /sshd/) print }' /var/log/messages > fail_login
awk '{ if($6 ~ /Accepted/ && $2 ~ /$Yesterday/) print }' /var/log/auth.log > login_log
df > hard_disk
cat /var/log/setuid.today > setuid_log

touch logs_all
echo "fail login log" >> logs_all
cat fail_login >> logs_all
echo "" >> logs_all
echo "login log" >> logs_all
cat login_log >> logs_all
echo "" >> logs_all
echo "hard disk log" >> logs_all
cat hard_disk >> logs_all
echo "" >> logs_all
echo "setuid log" >> logs_all
cat setuid_log >> logs_all

mail -s "server's log" jingfei955047@gmail.com < ./$Date/logs/logs_all

