#!/bin/bash

course_file="$1"
#task 1------------------------------------------------------------------------
#check if the formart is right

if [ "$#" -ne 1 ]; then
  echo "Wrong number of arguments" >&2
  exit 1
fi

shopt -s extglob   # Enable extended pattern matching features

# Check if the course file exists
if [[ ! -e "${course_file}" ]]; then
    echo "Course not found" >&2
    exit 1
fi

#task 2------------------------------------------------------------------------

# remove existed folder
dir_name="${course_file}_stat"
if [ -d "$dir_name" ]; then
	rm -rf "$dir_name";
fi

#makeinga new folder
mkdir "$dir_name"

#task 3------------------------------------------------------------------------

output_file_hist="${dir_name}/histogram.txt"
output_file_stat="${dir_name}/statistics.txt"
./hist.exe "${course_file}" > "$output_file_hist"


{
    ./mean.exe "$course_file"
	echo -ne "\t"
	./median.exe "$course_file"
	echo -ne "\t"
	./min.exe "$course_file"
	echo -ne "\t"
	./max.exe "$course_file"
	echo -ne "\n"
} >> "$output_file_stat"