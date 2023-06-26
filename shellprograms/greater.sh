echo "Enter two numbers"
read a b
if [ $a -gt $b ]; then
    echo "$a is greater than $b"
elif [ $b -gt $a ]; then
    echo "$b is greater than $a"
else
    echo "Both the number, $b are equal"
fi