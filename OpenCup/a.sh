g++ -fsanitize=address -ftrapv data.cpp -o data
g++ -fsanitize=address -ftrapv e.cpp -o e
g++ -fsanitize=address -ftrapv e_bf.cpp -o bf

while true;do
	./data
	./e <inp.in >e.out
	./bf <inp.in >bf.out
if diff e.out bf.out
then
	echo 'AC'
else
	echo 'WA'
	exit
fi
done



# g++ -fsanitize=address -ftrapv data.cpp -o data
# g++ -fsanitize=address -ftrapv e.cpp -o e
# g++ -fsanitize=address -ftrapv e_bf.cpp -o bf

# ./data >inp.in
# ./e <inp.in >e.out
# ./bf <inp.in >bf.out
