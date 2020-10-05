#! /bin/sh

find /home/dereandor/Downloads -regextype posix-egrep -not -regex ".*\.(zip|gz)" -size 10k -atime +6 -exec gzip {} \; 
