g++ data.cpp -o data -O2
g++ 2.cpp -o 2 -O2
g++ 2.1.cpp -o 2.1 -O2

while true;do
./data
./2
./2.1
if diff mooriokart.out force.out
then
echo 'AC'
else
echo 'WA'
exit 0
fi
done