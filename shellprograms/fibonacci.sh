n1=0
n2=1
echo "Enter number"
read n
echo "The fibonacci series"
while [ $n -ge 0 ]; do
    echo "$n1"
    nxt=$((n1+n2))
    n1=$((n2))
    n2=$((nxt))
    n=$((n-1))
done
