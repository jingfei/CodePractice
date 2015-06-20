#!bin/sh

rsync -avlR --delete -e ssh imslab.org:/home/jingfei/backup/ /home/jingfei/backup/
