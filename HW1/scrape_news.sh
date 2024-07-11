#!/bin/bash

# give a name for the link
site="https://www.ynetnews.com/category/3082"

# fetch the content
data=$(wget --no-check-certificate -O - $site 2> /dev/null )

articles=$(echo "$data" | \
		   grep -oP "https://(www.)?ynetnews.com/article/[0-9a-zA-Z]+" | \
		   sort | \
		   uniq)
		   
Names=("Netanyahu" "Gantz")

declare -A word_counts

		   
for article in $articles; do

    article_site=$(wget --no-check-certificate -O - "$article" 2> /dev/null )

    flag=0

    for name in "${Names[@]}"; do
        count=$(echo "$article_site" | grep -o "$name" | wc -w)
        word_counts[$name]=$count 
        if [[ $count -gt 0 ]]; then    
            flag=1
        fi
    done

    echo -n "$article"
    if [[ $flag -eq 1 ]]; then
        for name in "${Names[@]}"; do
            echo -n ", $name, ${word_counts[$name]}"
        done
    else
        echo -n ", -"
    fi

    flag=0

    echo 
done

