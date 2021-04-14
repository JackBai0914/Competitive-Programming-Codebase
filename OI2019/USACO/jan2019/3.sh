g++ 3.cpp -o ac
g++ 3.1.cpp -o force
g++ 3.2.cpp -o data
while true;
do
	./data
	./ac
	./force
if diff tracking2.out force.out
then
echo 'AC'
else
echo 'WA'
exit
fi
done
