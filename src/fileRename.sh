# fileRename : Script to rename all .png files to number starting from 1
#
# Author : Aleksandr Golovin (golo314@uw.edu)
#
# Note : Script file must be placed and run from folder in which you wish to rename files
#
#!/bin/bash
i=1

# For all png files
for file in *.png
do
	# new filename is number in i
        j=$( printf "$i" )

	# rename file
        mv "$file" "$j.png"

	# increment i
        (( i++ ))
done
