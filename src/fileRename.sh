#!/bin/bash
i=1
for file in *.png
do
        j=$( printf "$i" )
        mv "$file" "$j.png"
        (( i++ ))
done
