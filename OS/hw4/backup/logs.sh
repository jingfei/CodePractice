#!/bin/bash 
# Program:
#	the shell is for login file everyday
# History:
# 2014/10/29	JingFei
# 2014/11/13	JingFei

DATE_none=$(date -v-3d +%Y%m%d )
DATE=$( date +%Y%m%d )
DAY=$(date +%d )

cd /home/jingfei/logs/

awk -v DAY="$DAY" '{ if($5 ~ /sshd/ && $2 ~ DAY) print }' /var/log/messages > fail_login
awk -v DAY="$DAY" 'BEGIN{OFS=" "}{ if($6 ~ /Accepted/ && $2 ~ DAY) print $1,$2,$3,$5,$8,$9,$10,$11,$12,$13}' /var/log/auth.log > login_log
df > hard_disk
diff /var/log/setuid.yesterday /var/log/setuid.today > setuid_log

touch logs_all
Title=" System Log:"
echo $DATE $Title >> logs_all
echo "" >> logs_all
echo "[fail login log]" >> logs_all
cat fail_login >> logs_all
echo "" >> logs_all
echo "[login log]" >> logs_all
cat login_log >> logs_all
echo "" >> logs_all
echo "[hard disk log]" >> logs_all
cat hard_disk >> logs_all
echo "" >> logs_all
echo "[setuid log]" >> logs_all
cat setuid_log >> logs_all

mail -s "server's log" jingfei955047@gmail.com < ./$Date/logs/logs_all

