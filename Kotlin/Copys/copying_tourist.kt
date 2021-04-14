/*
  * COMPILE
    kotlinc a.kt -include-runtime -d outp.jar
    java -jar outp.jar

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
    
    println(list.joinToString(" "))
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
    repeat(readLine()!!.toInt())

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

    * multi-dimention array:
      var dp = Array(n1){Array(n2){Array(n3){Array(n4){IntArray(n5){0}}}}} //int dp[n1][n2][n3][n4][n5]

    * template:
      Array(n)
      Array(n, {0})
      Array(n, {i -> a[i]})


    
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

  * TreeSet
    var s = TreeSet <Long>()
    s.isEmpty()
    s.remove(x)
    s.add(x)
    var f = s.first()


  * Bit operations
    (a shl b) //a<<b
    (a shr b) //a>>b


  * Trivial Functions:
    - maxOf(a, b), minOf(a, b)
    - toInt() //2e9.toInt()


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
    while (t-- > 0) {
        var (n, k) = readInts()
        var g = Array(n, { ArrayList<Pair<Int, Int>>() })
        for (i in 0..n - 2) {
            var (x, y) = readInts()
            x--
            y--
            g[x].add(Pair(y, i))
            g[y].add(Pair(x, i))
        }
        var deg = IntArray(n)
        var cnt = 0
        for (i in 0..n-1) {
            deg[i] = g[i].size
            if (deg[i] == 1) {
                cnt += 1
            }
        }
        if (cnt < k) {
            println("No")
            continue
        }
        if (k == 1) {
            println("Yes")
            println(1)
            println(1)
            continue
        }
        var que = ArrayList<Int>()
        for (i in 0..n-1) {
            if (deg[i] == 1) {
                que.add(i)
            }
        }
        var stay = IntArray(n) {1}
        var qIt = 0
        while (qIt < que.size && cnt > k) {
            stay[que[qIt]] = 0
            for (p in g[que[qIt]]) {
                var u = p.first
                --deg[u]
                if (deg[u] == 1) {
                    que.add(u)
                } else {
                    if (deg[u] > 1) {
                        --cnt
                    }
                }
            }
            qIt++
        }
        println("Yes")
        var take = ArrayList<Int>()
        for (i in 0 until n) {
            if (stay[i] == 1) {
                take.add(i + 1)
            }
        }
        println(take.size)
        println(take.joinToString(" "))
    }
}