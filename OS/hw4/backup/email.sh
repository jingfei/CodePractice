#!/bin/bash 
# Program:
#	the shell is to combine login files and email to myself
# History:
# 2014/10/29	JingFei
# 2014/11/13	JingFei

DATE_none=$(date -v-3d +%Y%m%d )
DATE=$( date +%Y%m%d )
DAY=$(date +%d )

cd /home/jingfei/logs/

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

mail -s "server's log" jingfei955047@gmail.com < logs_all

