/*
  * input&output
    private fun readLn() = readLine()!! // string line
    private fun readInt() = readLn().toInt() // single int
    private fun readLong() = readLn().toLong() // single long
    private fun readDouble() = readLn().toDouble() // single double
    private fun readStrings() = readLn().split(" ") // list of strings
    private fun readInts() = readStrings().map { it.toInt() } // list of ints
    private fun readLongs() = readStrings().map { it.toLong() } // list of longs
    private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

    read two integers: var (x, y) = readInts()
    

    println("${PAR} RANDOM_STRING")
    println(PAR)

  * main function:
    fun main(args: Array<String>) {
    }
  
  * parameters declaration:
    var x = something
  
  * for, while, if, else
    for (i in 1..n) //for (int i = 1; i <= n; i ++)
    for (i in 0 until n) //for (int i = 0; i < n; i ++)
    for (i in a) //a is a list, and i traverses all elements in a.
    for (i in n-1 downTo 0) //for (int i = n - 1; i >= 0; i --)

    while (t-- >0) // while ((t--) > 0)

    if/else: the same as C++
    (if(x>0) '1' else '0')

  * functions declaration
    fun F (x: Int) {
    
    }
    //so, you'd better see it as void function

  * IntArray, CharArray, Array
    var x = IntArray(n)
    var y = CharArray(n)
    x/joinToString(" ")
    y.joinToString("")
    var b = Array<Pair<Int, Int>>(n, {i -> Pair(a[i], i)})

    
  * List (currently no evidence that it's different from Array)
    var x = readInts()
    
  * Pair and self-defined sort
    var x = Pair(1, 2)
    var b = Array<Pair<Int, Int>>(n, {i -> Pair(a[i], i)})
    b.sortWith(compareBy({it.first}, {it.second}))

  * ArrayList //addable, like vector
    ArrayList<Int>()
    //HAVE PARAMETER: size
    //some combination:
    g = Array(n, {ArrayList<Pair<Int, Int>>() })
    g[a].add(Pair(a, b)), g[b].add(Pair(a, b))
    //or
    g = Array(n, {ArrayList<Int>() })
    g[a].add(b), g[b].add(a)



  Trivial Functions:
    maxOf(a, b), minOf(a, b)

*/
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    while (t-- >0) {
        var (a, b) = readInts()
        var (c, d) = readInts()
        if (a < b) {
            var x = a
            a = b
            b = x
        }   
        if (c < d) {
            var x = c
            c = d
            d = x
        } 
        if (a == c && b+d == a)
            println("Yes")
        else
            println("No")
    }    
}