if [ ! -f $1 ]; then
	touch $1
fi

echo "$2" > $1

while read line; do
	echo "$line"
done < $1

nc localhost 12345 
