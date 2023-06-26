fac=1
echo "Enter number"
read n
temp=$n
while [ $n -gt 0 ]; do
    fac=$((fac*n))
    n=$((n-1))
done
echo "The factorial of $temp is $fac"
