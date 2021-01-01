#!/bin/bash
# documentation
#
#
#
# end of documentation

width=$1
height=$2

curr_dir=$(pwd)
for entry in "${curr_dir}/"*
do
    file="$(basename -- $entry)"
    inkscape -z -e "${file%%.*}".png -w $width -h $height $file
done
