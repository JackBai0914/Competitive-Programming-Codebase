g++ -fsanitize=address -ftrapv data.cpp -o data -O2
g++ -fsanitize=address -ftrapv  a.cpp -o a -O2
g++ -fsanitize=address -ftrapv  a2.cpp -o a2 -O2


while true; do
./data >inp.in
./a <inp.in >outp.out
./a2 <inp.in >outp2.out
if diff outp.out outp2.out
then
echo 'AC'
else
echo 'WA'
exit
fi
done