sum=0
echo "Enter number"
read n
while [ $n -gt 0 ]; do
    sum=$((sum+n))
    n=$((n-1))
done
echo "The sum is $sum"
